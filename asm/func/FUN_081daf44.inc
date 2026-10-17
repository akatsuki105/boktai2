	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r1, _081DAF94 @ =0x0000032D
	adds r0, r3, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081DAF98 @ =0x00000323
	adds r0, r3, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r3, r2
	strb r1, [r0]
	ldr r0, _081DAF9C @ =0x00000326
	adds r1, r3, r0
	movs r0, #3
	strb r0, [r1]
	adds r2, #3
	adds r1, r3, r2
	movs r0, #4
	strb r0, [r1]
	movs r6, #0
	ldr r0, _081DAFA0 @ =0x03002C68
	ldr r0, [r0]
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0
	beq _081DAF7C
	ldrh r5, [r0, #0x1a]
_081DAF7C:
	movs r1, #0
	cmp r6, r5
	bge _081DAFB6
	adds r2, r0, #0
	movs r4, #0xd2
	lsls r4, r4, #1
_081DAF88:
	cmp r2, #0
	beq _081DAF90
	cmp r1, #0
	bge _081DAFA4
_081DAF90:
	movs r0, #0
	b _081DAFA6
	.align 2, 0
_081DAF94: .4byte 0x0000032D
_081DAF98: .4byte 0x00000323
_081DAF9C: .4byte 0x00000326
_081DAFA0: .4byte 0x03002C68
_081DAFA4:
	adds r0, r2, r4
_081DAFA6:
	ldr r0, [r0, #0x18]
	cmp r0, #2
	bhi _081DAFAE
	movs r6, #1
_081DAFAE:
	adds r4, #0x48
	adds r1, #1
	cmp r1, r5
	blt _081DAF88
_081DAFB6:
	cmp r6, #0
	beq _081DAFD4
	ldr r1, _081DAFCC @ =0x00000325
	adds r0, r3, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _081DAFD0 @ =0x00000322
	adds r0, r3, r2
	strb r1, [r0]
	b _081DAFE2
	.align 2, 0
_081DAFCC: .4byte 0x00000325
_081DAFD0: .4byte 0x00000322
_081DAFD4:
	ldr r1, _081DAFE8 @ =0x00000325
	adds r0, r3, r1
	movs r1, #2
	strb r1, [r0]
	ldr r2, _081DAFEC @ =0x00000322
	adds r0, r3, r2
	strb r6, [r0]
_081DAFE2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DAFE8: .4byte 0x00000325
_081DAFEC: .4byte 0x00000322
