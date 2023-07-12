import { ComponentFixture, TestBed } from '@angular/core/testing';

import { AddEditComputerComponent } from './add-edit-computer.component';

describe('AddEditComputerComponent', () => {
  let component: AddEditComputerComponent;
  let fixture: ComponentFixture<AddEditComputerComponent>;

  beforeEach(() => {
    TestBed.configureTestingModule({
      declarations: [AddEditComputerComponent]
    });
    fixture = TestBed.createComponent(AddEditComputerComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
