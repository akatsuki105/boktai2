	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0816C47C @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816C480
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816C482
	.align 2, 0
_0816C47C: .4byte 0x0000046C
_0816C480:
	movs r0, #0
_0816C482:
	cmp r0, #0
	beq _0816C564
	ldr r3, _0816C4EC @ =Ghost_AnimFlungOff
	movs r2, #0x23
	ldr r6, _0816C4F0 @ =0x0000046D
	adds r1, r5, r6
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0816C4F4 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	adds r0, r5, #0
	bl Ghost_RestorePlayerSpeed
	ldr r2, _0816C4F8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816C4FC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r6, _0816C500 @ =0x0203B400
	adds r0, r0, r6
	ldrb r6, [r0]
	ldr r0, _0816C504 @ =0x00000888
	adds r1, r7, r0
	str r4, [sp]
	mov r0, sp
	ldr r2, _0816C508 @ =0x05000002
	bl CpuSet
	ldr r1, _0816C50C @ =gSineTable
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0816C510
	asrs r1, r0, #0xc
	b _0816C516
	.align 2, 0
_0816C4EC: .4byte Ghost_AnimFlungOff
_0816C4F0: .4byte 0x0000046D
_0816C4F4: .4byte 0x0000046B
_0816C4F8: .4byte 0x030046B8
_0816C4FC: .4byte 0x000003FF
_0816C500: .4byte 0x0203B400
_0816C504: .4byte 0x00000888
_0816C508: .4byte 0x05000002
_0816C50C: .4byte gSineTable
_0816C510:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816C516:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r2, _0816C53C @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0816C540
	asrs r0, r0, #0xc
	b _0816C546
	.align 2, 0
_0816C53C: .4byte gSineTable
_0816C540:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816C546:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r6, #0xe0
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r6, #0
	ldrsh r1, [r1, r6]
	bl ArcTan2_8
	subs r0, #0x80
	strb r0, [r5, #5]
_0816C564:
	ldr r1, _0816C610 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816C570
	b _0816C688
_0816C570:
	adds r0, r5, #0
	bl Ghost_StopChase
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r4, #0
	str r4, [sp]
	mov r0, sp
	ldr r2, _0816C614 @ =0x05000002
	bl CpuSet
	movs r1, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	ldr r2, _0816C618 @ =0x00000469
	adds r0, r5, r2
	strb r4, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0816C61C @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #3
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0816C620 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0816C610 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	adds r0, r5, #0
	bl Ghost_PickRandomPathNode
	add r6, sp, #4
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #8]
	ldrh r0, [r1]
	strh r0, [r6]
	ldrh r1, [r1, #2]
	strh r1, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r7, r6, #0
	cmp r2, #0
	blt _0816C60A
	cmp r1, #0
	blt _0816C60A
	ldr r0, _0816C624 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0816C60A
	ldr r0, _0816C628 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0816C62C
_0816C60A:
	movs r4, #0
	b _0816C63A
	.align 2, 0
_0816C610: .4byte 0x0000046B
_0816C614: .4byte 0x05000002
_0816C618: .4byte 0x00000469
_0816C61C: .4byte 0x00000484
_0816C620: .4byte Enemy_ClearStateBegun
_0816C624: .4byte 0x030046A8
_0816C628: .4byte 0x030046AC
_0816C62C:
	ldr r0, _0816C64C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0816C63A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0816C650
	adds r0, #4
	b _0816C65C
	.align 2, 0
_0816C64C: .4byte 0x030046A4
_0816C650:
	ldr r0, _0816C670 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0816C65C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0816C674
	cmp r2, #2
	beq _0816C678
	b _0816C67C
	.align 2, 0
_0816C670: .4byte 0x030046A4
_0816C674:
	ldrb r0, [r6, #4]
	b _0816C67A
_0816C678:
	ldrb r0, [r6]
_0816C67A:
	subs r1, r1, r0
_0816C67C:
	strh r1, [r6, #2]
	adds r0, r5, #0
	adds r1, r7, #0
	bl Ghost_BeginCurveTo
	b _0816C692
_0816C688:
	ldr r6, _0816C69C @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0816C692:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816C69C: .4byte 0x00000484
