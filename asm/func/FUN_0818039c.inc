	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081803B4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081803B8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081803BA
	.align 2, 0
_081803B4: .4byte 0x0000046D
_081803B8:
	movs r0, #0
_081803BA:
	cmp r0, #0
	beq _081803D4
	adds r0, r5, #0
	movs r1, #0x14
	bl Enemy_PlayAnimNoFacing
	adds r0, r5, #0
	bl FUN_0817dbfc
	movs r0, #0xb5
	lsls r0, r0, #2
	bl PlaySound_082406e0
_081803D4:
	ldr r1, _0818040C @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08180406
	ldr r4, _08180410 @ =FUN_0818041c
	movs r3, #0x2b
	ldr r0, _08180414 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08180418 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08180406:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0818040C: .4byte 0x0000046E
_08180410: .4byte FUN_0818041c
_08180414: .4byte 0x0000046D
_08180418: .4byte 0x0000046B
