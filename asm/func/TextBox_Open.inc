	push {lr}
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _08047A1A
	bl VM_GetPC
	b _08047A1E
_08047A1A:
	bl FUN_0823d340
_08047A1E:
	bl TextBox_Start
	pop {r1}
	bx r1
	.align 2, 0
