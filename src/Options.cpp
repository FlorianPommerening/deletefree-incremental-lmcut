#include "Options.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/filesystem.hpp>


using namespace std;

bool stringToBool(string value) {
    return (value == "1" || boost::iequals(value, "true") || boost::iequals(value,"yes"));
}

OptimizationOptions::OptimizationOptions(std::string optionsFilename) {
    // set default values
    // TODO should use better defaults
    this->resultDirectory = "./results/";
    this->translationsCacheDirectory = "../../translations/";
    this->translateRelaxedCommand = "../translate/translate-relaxed.py";
    // initialize random seed
    ifstream urandom("/dev/urandom", ios::in|ios::binary);
    urandom.read(reinterpret_cast<char*>(&(this->randomSeed)), sizeof(this->randomSeed));
    urandom.close();
    this->initialUpperBound = true;
    this->improveIntermediatePlans = true;
    this->idaStarSearch = false;
    this->selectOperatorInSmallestLandmark = true;
    this->tryGoalOnZeroHeuristic = true;
    this->autoApplyUnitLandmarks = true;
    this->autoApplyZeroCostOperators = true;
    this->avoidExpandingSecondSuccessor = true;
    this->incrementalSearch = true;
    this->preferOperatorsFromCurrentPlan = true;
    this->breakOnFirstSolution = false;
    this->expansionLimit = 0;
    this->restartTime = 0;
    this->geometricallyIncreasedRestartTime = false;
    ifstream optionsFile(optionsFilename.c_str());
    if (!optionsFile.is_open()) {
        cout << "No option file, using default options" << endl;
        return;
    }
    string optionsLine;
    vector<string> lineTokens;
    while (optionsFile.good()) {
      getline(optionsFile, optionsLine);
          boost::trim(optionsLine);
          if (optionsLine.empty() || optionsLine[0] == '#') {
              continue;
          }
          boost::split(lineTokens, optionsLine, boost::is_any_of("\t ="), boost::token_compress_on);
          string option = lineTokens[0];
          string value = "true";
          if (lineTokens.size() > 1) {
              value = lineTokens[1];
          }
          // set parsed option
          if (option == "resultDirectory") {
              this->resultDirectory = value;
          }
          else if (option == "translationsCacheDirectory") {
              this->translationsCacheDirectory = value;
          }
          else if (option == "translateRelaxedCommand") {
              this->translateRelaxedCommand = value;
          }
          else if (option == "randomSeed") {
              this->randomSeed = boost::lexical_cast<unsigned int>(value);
          }
          else if (option == "initialUpperBound") {
              this->initialUpperBound = stringToBool(value);
          }
          else if (option == "improveIntermediatePlans") {
              this->improveIntermediatePlans = stringToBool(value);
          }
          else if (option == "idaStarSearch") {
              this->idaStarSearch = stringToBool(value);
          }
          else if (option == "selectOperatorInSmallestLandmark") {
              this->selectOperatorInSmallestLandmark = stringToBool(value);
          }
          else if (option == "tryGoalOnZeroHeuristic") {
              this->tryGoalOnZeroHeuristic = stringToBool(value);
          }
          else if (option == "autoApplyUnitLandmarks") {
              this->autoApplyUnitLandmarks = stringToBool(value);
          }
          else if (option == "autoApplyZeroCostOperators") {
              this->autoApplyZeroCostOperators = stringToBool(value);
          }
          else if (option == "avoidExpandingSecondSuccessor") {
              this->avoidExpandingSecondSuccessor = stringToBool(value);
          }
          else if (option == "incrementalSearch") {
              this->incrementalSearch = stringToBool(value);
          }
          else if (option == "preferOperatorsFromCurrentPlan") {
              this->preferOperatorsFromCurrentPlan = stringToBool(value);
          }
          else if (option == "breakOnFirstSolution") {
              this->breakOnFirstSolution = stringToBool(value);
          }
          else if (option == "expansionLimit") {
              this->expansionLimit = boost::lexical_cast<int>(value);
          }
          else if (option == "restartTime") {
              this->restartTime = boost::lexical_cast<int>(value);
          }
          else if (option == "geometricallyIncreasedRestartTime") {
              this->geometricallyIncreasedRestartTime = stringToBool(value);
          }
    }
    optionsFile.close();

    if (this->geometricallyIncreasedRestartTime && this->restartTime == 0){
        this->restartTime = 1;
    }
    // create directories if not already there
    boost::filesystem::create_directories( this->resultDirectory );
    boost::filesystem::create_directories( this->translationsCacheDirectory );

}
