	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r1, _0808919C @ =0x000001F5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #8
	beq _08089160
	adds r0, r7, #0
	movs r1, #8
	bl Coffin_SetState
_08089160:
	ldr r2, _080891A0 @ =0x0000032A
	adds r0, r7, r2
	movs r6, #0
	strh r6, [r0]
	movs r0, #0xfb
	lsls r0, r0, #1
	adds r5, r7, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080891AE
	ldr r1, _080891A4 @ =0x0000031E
	adds r0, r7, r1
	strh r6, [r0]
	subs r2, #8
	adds r0, r7, r2
	strh r6, [r0]
	movs r0, #0xc8
	lsls r0, r0, #2
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0x1e
	bhi _080891A8
	adds r0, r7, #0
	bl FUN_080856cc
	strh r6, [r4]
	movs r0, #1
	strh r0, [r5]
	b _0808927A
	.align 2, 0
_0808919C: .4byte 0x000001F5
_080891A0: .4byte 0x0000032A
_080891A4: .4byte 0x0000031E
_080891A8:
	subs r0, #0x1e
	strh r0, [r4]
	b _0808927A
_080891AE:
	adds r1, r0, #1
	strh r1, [r5]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080891DE
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _080891CE
	lsls r1, r1, #4
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	b _080891E6
_080891CE:
	movs r0, #7
	subs r0, r0, r1
	lsls r0, r0, #4
	movs r6, #0xc8
	lsls r6, r6, #2
	adds r1, r7, r6
	strh r0, [r1]
	b _080891E6
_080891DE:
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r6, [r0]
_080891E6:
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r2, r2, r7
	mov r8, r2
	ldrh r0, [r2]
	cmp r0, #0xb
	bhi _0808922A
	ldr r6, _08089288 @ =0x0203B400
	mov ip, r6
	ldr r5, _0808928C @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _08089290 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, ip
	ldrh r0, [r0]
	movs r4, #0x1f
	ands r0, r4
	subs r0, #0x10
	ldr r6, _08089294 @ =0x0000031E
	adds r2, r7, r6
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #0x10
	ldr r2, _08089298 @ =0x00000322
	adds r1, r7, r2
	strh r0, [r1]
_0808922A:
	mov r6, r8
	ldrh r0, [r6]
	cmp r0, #2
	bne _08089238
	adds r0, r7, #0
	bl FUN_0808596c
_08089238:
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #0x1d
	bls _0808927A
	adds r0, r7, #0
	movs r1, #0
	bl Coffin_SetState
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #1
	strh r0, [r1]
	ldr r6, _0808929C @ =0x00000326
	adds r2, r7, r6
	ldr r3, _080892A0 @ =0x0000011F
	strh r3, [r2]
	ldr r0, _080892A4 @ =0x00000414
	adds r4, r7, r0
	ldr r0, [r4]
	adds r1, r7, #0
	adds r1, #0x40
	str r2, [sp]
	str r3, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #1
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
_0808927A:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08089288: .4byte 0x0203B400
_0808928C: .4byte 0x030046B8
_08089290: .4byte 0x000003FF
_08089294: .4byte 0x0000031E
_08089298: .4byte 0x00000322
_0808929C: .4byte 0x00000326
_080892A0: .4byte 0x0000011F
_080892A4: .4byte 0x00000414
