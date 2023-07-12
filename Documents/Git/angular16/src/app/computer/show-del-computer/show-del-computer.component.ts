import { Component,OnInit } from '@angular/core';
import { SharedService } from 'src/app/shared.service';

@Component({
  selector: 'app-show-del-computer',
  templateUrl: './show-del-computer.component.html',
  styleUrls: ['./show-del-computer.component.css']
})
export class ShowDelComputerComponent implements OnInit {

  constructor(private service:SharedService) { }

  ComputerList: any[] = [];
  ModalTitle: string = '';
  ActivateAddEditComputadorComp: boolean = false;
  pc: any;

  ngOnInit(): void { 
    this.refreshComputerList();
  }

  addClick(){
    this.pc={
      id: 0,
      placa_mae: "",
      processador: "",
      memoria_ram: 0,
      armazenamento: 0,
      gpu: "",
      fonte: ""
    }
    this.ModalTitle="Adicionar Computador";
    this.ActivateAddEditComputadorComp = true;
  }

  editClick(item: any){
    this.pc = item;
    this.ModalTitle="Alterar Computador";
    this.ActivateAddEditComputadorComp = true;
  }

  deleteClick(item: any){
    if(confirm('Tem certeza que deseja deletar?')){
      this.service.deleteComputer(item.id).subscribe(data=>{
        alert(data.toString());
        this.refreshComputerList();
      })
    }
  }

  closeClick(){
    this.ActivateAddEditComputadorComp = false;
    this.refreshComputerList();
  }

  refreshComputerList(){
    this.service.getComputerList().subscribe(data=>{
      this.ComputerList = data;
    })
  }
}