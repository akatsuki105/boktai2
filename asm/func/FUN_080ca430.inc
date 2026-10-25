	push {r4, lr}
	movs r0, #5
	bl Boss_Get
	adds r4, r0, #0
	cmp r4, #0
	beq _080CA4CC
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080CA458
	bl VM_GetValue
	ldr r2, _080CA454 @ =0x00002606
	adds r1, r4, r2
	b _080CA460
	.align 2, 0
_080CA454: .4byte 0x00002606
_080CA458:
	ldr r0, _080CA478 @ =0x00002606
	adds r1, r4, r0
	movs r0, #0x96
	lsls r0, r0, #2
_080CA460:
	strh r0, [r1]
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080CA480
	bl VM_GetValue
	ldr r2, _080CA47C @ =0x00002604
	adds r1, r4, r2
	b _080CA486
	.align 2, 0
_080CA478: .4byte 0x00002606
_080CA47C: .4byte 0x00002604
_080CA480:
	ldr r0, _080CA4A0 @ =0x00002604
	adds r1, r4, r0
	movs r0, #0xb4
_080CA486:
	strh r0, [r1]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080CA4A8
	bl VM_GetValue
	ldr r2, _080CA4A4 @ =0x00002608
	adds r1, r4, r2
	str r0, [r1]
	b _080CA4AE
	.align 2, 0
_080CA4A0: .4byte 0x00002604
_080CA4A4: .4byte 0x00002608
_080CA4A8:
	ldr r2, _080CA4D4 @ =0x00002608
	adds r0, r4, r2
	str r1, [r0]
_080CA4AE:
	ldr r2, _080CA4D8 @ =FUN_080c6538
	movs r0, #0x38
	adds r3, r4, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080CA4CC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CA4D4: .4byte 0x00002608
_080CA4D8: .4byte FUN_080c6538
