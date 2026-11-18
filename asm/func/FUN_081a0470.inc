	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r0, #0x4f
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081A0526
	bl VM_GetPC
	cmp r0, #0
	beq _081A0494
	bl VM_GetValue
	adds r1, r0, #0
	b _081A0496
_081A0494:
	movs r1, #6
_081A0496:
	ldr r2, _081A04AC @ =0x00000E3C
	adds r0, r4, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A04B0
	bl VM_GetValue
	adds r1, r0, #0
	b _081A04B2
	.align 2, 0
_081A04AC: .4byte 0x00000E3C
_081A04B0:
	movs r1, #0xc
_081A04B2:
	ldr r2, _081A04C8 @ =0x00000E3D
	adds r0, r4, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A04CC
	bl VM_GetValue
	adds r1, r0, #0
	b _081A04CE
	.align 2, 0
_081A04C8: .4byte 0x00000E3D
_081A04CC:
	movs r1, #0x3c
_081A04CE:
	ldr r2, _081A04E4 @ =0x00000E3E
	adds r0, r4, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A04E8
	bl VM_GetValue
	adds r1, r0, #0
	b _081A04EA
	.align 2, 0
_081A04E4: .4byte 0x00000E3E
_081A04E8:
	movs r1, #3
_081A04EA:
	ldr r2, _081A0500 @ =0x00000E3F
	adds r0, r4, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A0504
	bl VM_GetValue
	adds r1, r0, #0
	b _081A0506
	.align 2, 0
_081A0500: .4byte 0x00000E3F
_081A0504:
	movs r1, #0x3c
_081A0506:
	movs r2, #0xe4
	lsls r2, r2, #4
	adds r0, r4, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A051E
	bl VM_GetValue
	adds r1, r0, #0
	b _081A0520
_081A051E:
	movs r1, #0x1e
_081A0520:
	ldr r2, _081A052C @ =0x00000E41
	adds r0, r4, r2
	strb r1, [r0]
_081A0526:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081A052C: .4byte 0x00000E41
