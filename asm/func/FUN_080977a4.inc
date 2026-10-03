	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, _080977EC @ =0x000009EE
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080977B8
	ldr r0, _080977F0 @ =0x0000038A
	bl PlaySound_082406e0
_080977B8:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _08097804
	ldrh r0, [r4]
	movs r4, #0xc
	subs r4, r4, r0
	ldr r1, _080977F4 @ =0x000020C4
	adds r0, r7, r1
	ldr r2, _080977F8 @ =0x00003B68
	adds r1, r7, r2
	adds r2, r4, #0
	bl FUN_0808ba20
	ldr r1, _080977FC @ =0x00002124
	adds r0, r7, r1
	ldr r2, _08097800 @ =0x00003B70
	adds r1, r7, r2
	adds r2, r4, #0
	bl FUN_0808ba20
	b _08097882
	.align 2, 0
_080977EC: .4byte 0x000009EE
_080977F0: .4byte 0x0000038A
_080977F4: .4byte 0x000020C4
_080977F8: .4byte 0x00003B68
_080977FC: .4byte 0x00002124
_08097800: .4byte 0x00003B70
_08097804:
	ldr r0, _08097860 @ =0x000020AC
	adds r1, r7, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08097864 @ =0x0000210C
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _08097868 @ =0x00003AEE
	adds r5, r7, r1
	ldrb r1, [r5]
	ldr r0, _0809786C @ =0x030046A0
	ldr r3, [r0]
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r1, r1, r2
	movs r0, #0
	ldrsh r4, [r1, r0]
	ldr r0, _08097870 @ =0x00003AEB
	adds r6, r7, r0
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r3
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r3
	adds r0, r0, r2
	strh r4, [r0]
	adds r3, #0x5c
	movs r1, #0
	ldrsh r0, [r3, r1]
	ldrb r1, [r5]
	cmp r0, r1
	bne _08097874
	ldrb r0, [r6]
	strh r0, [r3]
	b _0809787C
	.align 2, 0
_08097860: .4byte 0x000020AC
_08097864: .4byte 0x0000210C
_08097868: .4byte 0x00003AEE
_0809786C: .4byte 0x030046A0
_08097870: .4byte 0x00003AEB
_08097874:
	ldrb r6, [r6]
	cmp r0, r6
	bne _0809787C
	strh r1, [r3]
_0809787C:
	adds r0, r7, #0
	bl FUN_08096fa8
_08097882:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
