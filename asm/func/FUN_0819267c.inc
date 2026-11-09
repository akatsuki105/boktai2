	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _081926BC
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	movs r2, #8
	ldrsh r0, [r5, r2]
	movs r3, #0xc
	ldrsh r1, [r5, r3]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrh r2, [r2]
	adds r4, #0x1d
	adds r3, r5, r4
	ldrb r3, [r3]
	ldrh r4, [r5]
	str r4, [sp]
	bl FUN_08240dc8
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	bge _081926C0
_081926BC:
	movs r0, #0
	b _08192722
_081926C0:
	adds r0, r5, #0
	bl FUN_080e8f20
	ldr r1, _0819272C @ =0x00000D4F
	adds r0, r7, r1
	strb r6, [r0]
	movs r1, #0x17
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _08192730 @ =0x00000469
	adds r0, r5, r3
	strb r6, [r0]
	ldr r4, _08192734 @ =0x0000046A
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _08192738 @ =0x00000484
	adds r0, r5, r1
	str r6, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0819273C @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r4, #3
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _08192740 @ =0x0000046B
	adds r0, r5, r1
	strb r6, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	adds r0, r5, #0
	bl FUN_0819394c
	bl FUN_080df478
	movs r0, #1
_08192722:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0819272C: .4byte 0x00000D4F
_08192730: .4byte 0x00000469
_08192734: .4byte 0x0000046A
_08192738: .4byte 0x00000484
_0819273C: .4byte Enemy_ClearStateBegun
_08192740: .4byte 0x0000046B
