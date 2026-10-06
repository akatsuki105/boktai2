	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r1, _08063888 @ =0x00000446
	adds r0, r4, r1
	ldrh r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _0806382A
	b _08063948
_0806382A:
	subs r1, #4
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #5
	bne _08063894
	ldr r0, _0806388C @ =0x0000097A
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0x3f
	bhi _08063858
	cmp r0, #0
	bne _08063852
	movs r0, #0xf7
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, _08063890 @ =0x000003F1
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08063852:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_08063858:
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r1, _0806388C @ =0x0000097A
	adds r0, r4, r1
	ldrh r0, [r0]
	lsrs r0, r0, #1
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0xb
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	adds r5, r2, #0
	b _080638FA
	.align 2, 0
_08063888: .4byte 0x00000446
_0806388C: .4byte 0x0000097A
_08063890: .4byte 0x000003F1
_08063894:
	ldr r0, _080638D4 @ =0x0000097A
	adds r6, r4, r0
	ldrh r0, [r6]
	adds r5, r4, #0
	adds r5, #0x90
	cmp r0, #0
	beq _080638FA
	ldr r1, _080638D8 @ =0x000003F1
	adds r7, r4, r1
	ldrb r0, [r7]
	cmp r0, #0
	beq _080638B6
	ldr r0, _080638DC @ =0x00000336
	bl PlaySound_082406e0
	movs r0, #0
	strb r0, [r7]
_080638B6:
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080638E0
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r1, #0x40
	b _080638F4
	.align 2, 0
_080638D4: .4byte 0x0000097A
_080638D8: .4byte 0x000003F1
_080638DC: .4byte 0x00000336
_080638E0:
	ldr r0, [r5]
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	ldrh r0, [r6]
	lsrs r0, r0, #1
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
_080638F4:
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_080638FA:
	ldr r1, _0806391C @ =0x00000442
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #6
	bne _08063920
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	b _08063928
	.align 2, 0
_0806391C: .4byte 0x00000442
_08063920:
	ldr r0, [r5]
	ldr r1, _08063940 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r5]
_08063928:
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080639C0
	ldr r0, _08063944 @ =0x00000446
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _080639C0
	.align 2, 0
_08063940: .4byte 0xFFFFFDFF
_08063944: .4byte 0x00000446
_08063948:
	ldr r1, _08063988 @ =0x0000097A
	adds r6, r4, r1
	ldrh r0, [r6]
	adds r5, r4, #0
	adds r5, #0x90
	cmp r0, #0
	beq _080639AE
	ldr r0, _0806398C @ =0x000003F1
	adds r7, r4, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _0806396A
	ldr r0, _08063990 @ =0x00000336
	bl PlaySound_082406e0
	mov r1, r8
	strb r1, [r7]
_0806396A:
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08063994
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r1, #0x40
	b _080639A8
	.align 2, 0
_08063988: .4byte 0x0000097A
_0806398C: .4byte 0x000003F1
_08063990: .4byte 0x00000336
_08063994:
	ldr r0, [r5]
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	ldrh r0, [r6]
	lsrs r0, r0, #1
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
_080639A8:
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_080639AE:
	ldr r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080639C0
	ldr r0, _080639CC @ =0xFFFFFDFF
	ands r1, r0
	str r1, [r5]
_080639C0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080639CC: .4byte 0xFFFFFDFF
