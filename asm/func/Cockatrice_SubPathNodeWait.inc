	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r5, r0, #0
	adds r6, r5, #0
	ldr r0, _08158698 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081585D6
	movs r0, #0
	strb r0, [r1]
_081585D6:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081585EC
	b _08158772
_081585EC:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081585FA
	b _08158772
_081585FA:
	ldr r1, [r6, #0x24]
	ldr r0, [r1, #8]
	ldrb r0, [r0, #6]
	lsrs r4, r0, #4
	cmp r4, #0
	beq _08158622
	cmp r4, #2
	beq _08158622
	cmp r4, #4
	beq _08158622
	adds r0, r1, #0
	bl Map_AdvancePathWalker
	ldr r0, [r6, #0x24]
	ldr r0, [r0, #8]
	ldrb r0, [r0, #6]
	lsrs r4, r0, #4
	cmp r4, #1
	bne _08158622
	b _08158772
_08158622:
	ldr r2, [r6, #0x24]
	ldrb r1, [r2, #3]
	adds r0, r1, #1
	strb r0, [r2, #3]
	lsls r1, r1, #0x18
	ldr r0, [r6, #0x24]
	ldr r0, [r0, #8]
	ldrh r2, [r0, #4]
	ldr r0, _0815869C @ =0x00000FFF
	lsrs r1, r1, #0x18
	ands r0, r2
	cmp r1, r0
	bhs _0815863E
	b _08158768
_0815863E:
	movs r3, #0xca
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _08158676
	adds r0, r5, #0
	adds r0, #0x9e
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r5]
	str r0, [sp, #4]
	ldr r1, _081586A0 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	str r0, [sp, #8]
	ldr r1, _081586A4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r3, sp
	str r3, [r1, #4]
	ldrh r0, [r2]
	bl VM_ExecByID
_08158676:
	ldr r0, [r6, #0x24]
	bl Map_AdvancePathWalker
	adds r0, r5, #0
	bl Enemy_StepTowardPathNode
	ldr r0, [r6, #0x24]
	ldr r0, [r0, #8]
	ldrb r0, [r0, #6]
	lsrs r4, r0, #4
	cmp r4, #4
	bne _081586AC
	ldr r0, _081586A8 @ =0x00000482
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	b _08158738
	.align 2, 0
_08158698: .4byte 0x0000046C
_0815869C: .4byte 0x00000FFF
_081586A0: .4byte 0x000001DF
_081586A4: .4byte 0xFFFF0000
_081586A8: .4byte 0x00000482
_081586AC:
	ldr r2, _081586FC @ =0x00000482
	adds r1, r5, r2
	movs r7, #0
	movs r3, #1
	mov r8, r3
	movs r0, #1
	strh r0, [r1]
	cmp r4, #0
	bne _08158738
	ldr r0, [r6, #0x24]
	adds r1, r6, #0
	adds r1, #8
	movs r2, #0x20
	movs r3, #0x20
	bl Map_IsPosOutsidePathNode
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08158708
	movs r1, #0xf
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _08158700 @ =0x00000469
	adds r0, r5, r3
	strb r7, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r4, [r0]
	ldr r1, _08158704 @ =0x0000046C
	adds r0, r5, r1
	mov r2, r8
	strb r2, [r0]
	b _08158772
	.align 2, 0
_081586FC: .4byte 0x00000482
_08158700: .4byte 0x00000469
_08158704: .4byte 0x0000046C
_08158708:
	movs r1, #0x10
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r7, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r7, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _08158730 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08158734 @ =0x0000046C
	adds r0, r5, r2
	mov r3, r8
	strb r3, [r0]
	b _08158772
	.align 2, 0
_08158730: .4byte 0x00000484
_08158734: .4byte 0x0000046C
_08158738:
	movs r2, #0xf
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08158760 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _08158764 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08158772
	.align 2, 0
_08158760: .4byte 0x00000469
_08158764: .4byte 0x00000484
_08158768:
	ldr r0, _08158780 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08158772:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08158780: .4byte 0x00000484
