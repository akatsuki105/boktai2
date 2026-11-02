	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	mov sb, r0
	mov r8, r1
	ldr r3, _0800308C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x20
	orrs r0, r2
	ldr r1, _08003090 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	movs r7, #0
	add r4, sp, #0x10
	ldr r6, _08003094 @ =0x030046B8
	ldr r5, _08003098 @ =0x000003FF
_08003042:
	ldr r0, [r6]
	adds r2, r0, #1
	ands r2, r5
	str r2, [r6]
	mov r3, sb
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	bne _080030A0
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	ldr r1, _0800309C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	add r0, r8
	ldrh r3, [r4]
	adds r0, r0, r3
	add r1, sp, #0x10
	strh r0, [r1]
	adds r2, #1
	ands r2, r5
	str r2, [r6]
	lsls r2, r2, #1
	ldr r0, _0800309C @ =0x0203B400
	adds r2, r2, r0
	ldrh r0, [r4, #4]
	subs r0, #0x80
	ldrb r2, [r2]
	adds r0, r0, r2
	b _080030CC
	.align 2, 0
_0800308C: .4byte 0xFFFF0000
_08003090: .4byte 0x0000FFFF
_08003094: .4byte 0x030046B8
_08003098: .4byte 0x000003FF
_0800309C: .4byte 0x0203B400
_080030A0:
	adds r1, r2, #1
	ands r1, r5
	lsls r2, r1, #1
	ldr r3, _080030F8 @ =0x0203B400
	adds r2, r2, r3
	ldrh r0, [r4]
	subs r0, #0x80
	ldrb r2, [r2]
	adds r0, r0, r2
	add r2, sp, #0x10
	strh r0, [r2]
	adds r1, #1
	ands r1, r5
	str r1, [r6]
	lsls r1, r1, #1
	adds r1, r1, r3
	ldrh r0, [r1]
	movs r1, #0xf
	ands r0, r1
	add r0, r8
	ldrh r1, [r4, #4]
	adds r0, r0, r1
_080030CC:
	strh r0, [r4, #4]
	movs r0, #3
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #0
	add r2, sp, #8
	movs r3, #1
	bl FUN_080dbcec
	adds r7, #1
	cmp r7, #9
	ble _08003042
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080030F8: .4byte 0x0203B400
