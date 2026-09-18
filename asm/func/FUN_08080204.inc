	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	ldr r3, [r0, #0x18]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	mov r2, ip
	str r0, [r2, #0x38]
	str r1, [r2, #0x3c]
	mov r0, ip
	adds r0, #0xbc
	ldrh r0, [r0]
	ldrh r4, [r2, #0x3a]
	adds r0, r0, r4
	strh r0, [r2, #0x3a]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r7, r0, #5
	ldr r1, _08080270 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r6, [r0, r4]
	adds r0, r7, #0
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r5, [r0, r2]
	ldr r4, _08080274 @ =0x000002E7
	adds r3, r3, r4
	ldrb r0, [r3]
	mov r8, r1
	cmp r0, #0
	beq _080802D8
	mov r1, ip
	adds r1, #0xbe
	ldrh r0, [r1]
	muls r0, r6, r0
	adds r3, r1, #0
	cmp r0, #0
	blt _08080278
	asrs r0, r0, #0xc
	b _0808027E
	.align 2, 0
_08080270: .4byte 0x085B0A08
_08080274: .4byte 0x000002E7
_08080278:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808027E:
	adds r4, r0, #0
	mov r1, ip
	adds r1, #0xc0
	ldrh r0, [r1]
	muls r0, r5, r0
	adds r2, r1, #0
	cmp r0, #0
	blt _08080292
	asrs r0, r0, #0xc
	b _08080298
_08080292:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08080298:
	adds r0, r4, r0
	mov r1, ip
	ldrh r1, [r1, #0x38]
	adds r0, r0, r1
	mov r4, ip
	strh r0, [r4, #0x38]
	ldrh r0, [r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _080802B0
	asrs r0, r0, #0xc
	b _080802B6
_080802B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080802B6:
	adds r1, r0, #0
	ldrh r0, [r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _080802C4
	asrs r0, r0, #0xc
	b _080802CA
_080802C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080802CA:
	subs r0, r1, r0
	mov r1, ip
	ldrh r1, [r1, #0x3c]
	adds r0, r0, r1
	mov r2, ip
	strh r0, [r2, #0x3c]
	b _08080348
_080802D8:
	mov r1, ip
	adds r1, #0xbe
	ldrh r0, [r1]
	muls r0, r6, r0
	adds r3, r1, #0
	cmp r0, #0
	blt _080802EA
	asrs r0, r0, #0xc
	b _080802F0
_080802EA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080802F0:
	adds r4, r0, #0
	mov r1, ip
	adds r1, #0xc0
	ldrh r0, [r1]
	muls r0, r5, r0
	adds r2, r1, #0
	cmp r0, #0
	blt _08080304
	asrs r0, r0, #0xc
	b _0808030A
_08080304:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808030A:
	subs r0, r4, r0
	mov r4, ip
	ldrh r4, [r4, #0x38]
	adds r0, r0, r4
	mov r1, ip
	strh r0, [r1, #0x38]
	ldrh r0, [r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _08080322
	asrs r0, r0, #0xc
	b _08080328
_08080322:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08080328:
	adds r1, r0, #0
	ldrh r0, [r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08080336
	asrs r0, r0, #0xc
	b _0808033C
_08080336:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808033C:
	adds r0, r1, r0
	mov r2, ip
	ldrh r2, [r2, #0x3c]
	adds r0, r0, r2
	mov r4, ip
	strh r0, [r4, #0x3c]
_08080348:
	movs r2, #0xff
	lsrs r0, r7, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	mov r0, ip
	adds r0, #0xc8
	strb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r1, ip
	adds r1, #0xc2
	ldrh r0, [r1]
	muls r0, r2, r0
	adds r3, r1, #0
	cmp r0, #0
	blt _08080378
	asrs r2, r0, #0xc
	b _0808037E
_08080378:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0808037E:
	mov r0, ip
	adds r0, #0xb4
	strh r2, [r0]
	lsls r0, r7, #1
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08080398
	asrs r1, r0, #0xc
	b _0808039E
_08080398:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808039E:
	mov r0, ip
	adds r0, #0xb8
	strh r1, [r0]
	subs r0, #0x12
	strb r7, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
