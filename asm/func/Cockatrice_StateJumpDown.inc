	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	mov r8, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08155680 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08155684
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08155686
	.align 2, 0
_08155680: .4byte 0x0000046D
_08155684:
	movs r0, #0
_08155686:
	cmp r0, #0
	beq _081556F4
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r5, r7, r0
	adds r3, r6, #0
	adds r3, #8
	movs r1, #0xd6
	lsls r1, r1, #3
	adds r2, r7, r1
	ldrh r0, [r2]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	movs r4, #0
	strh r0, [r5]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r1, #0xa
	bl Div
	strh r0, [r5]
	ldr r1, _0815572C @ =0x000006AA
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, _08155730 @ =0x000006AC
	adds r4, r7, r2
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl Div
	strh r0, [r4]
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r2, #0
	ldrsh r1, [r4, r2]
	bl ArcTan2_8
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r6, #5]
	ldr r0, _08155734 @ =0x000001D5
	bl PlaySound_082406e0
_081556F4:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r7, r2
	mov r0, r8
	adds r0, #0x12
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #1
	movs r3, #4
	bl Cockatrice_StepJump
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08155738
	adds r0, r6, #0
	movs r1, #0x11
	bl Enemy_PlayAnim
	b _08155782
	.align 2, 0
_0815572C: .4byte 0x000006AA
_08155730: .4byte 0x000006AC
_08155734: .4byte 0x000001D5
_08155738:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r2, _08155790 @ =0x000006CA
	adds r0, r7, r2
	movs r3, #0
	movs r5, #0
	strh r1, [r0]
	ldr r4, _08155794 @ =Cockatrice_StateLand
	movs r2, #0x25
	ldr r0, _08155798 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0815579C @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r2, r7, r0
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08155782:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08155790: .4byte 0x000006CA
_08155794: .4byte Cockatrice_StateLand
_08155798: .4byte 0x0000046D
_0815579C: .4byte 0x0000046B
