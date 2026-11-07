	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _081645E8
	bl VM_GetPC
	cmp r0, #0
	beq _081645C4
	bl VM_GetValue
	adds r1, r0, #0
	b _081645C6
_081645C4:
	movs r1, #0
_081645C6:
	movs r2, #0xd1
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081645DE
	bl VM_GetValue
	adds r1, r0, #0
	b _081645E0
_081645DE:
	movs r1, #0
_081645E0:
	ldr r2, _081645E4 @ =0x0000068A
	b _081645F2
	.align 2, 0
_081645E4: .4byte 0x0000068A
_081645E8:
	movs r2, #0xd1
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
_081645F2:
	adds r0, r4, r2
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
