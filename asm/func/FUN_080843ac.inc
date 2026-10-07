	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	ldr r6, [r4, #0x1c]
	cmp r6, #1
	beq _080843BC
	b _0808453A
_080843BC:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r3, #6]
	ands r0, r1
	cmp r0, #0
	beq _080843DE
	adds r2, r5, #0
	adds r2, #0x46
	ldrb r1, [r2]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080843D8
	b _0808453A
_080843D8:
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2]
_080843DE:
	adds r0, r3, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x44
	movs r2, #0
	mov ip, r2
	strh r1, [r0]
	movs r7, #0xdf
	lsls r7, r7, #2
	adds r0, r4, r7
	ldrb r0, [r0]
	cmp r0, #8
	bne _0808449C
	ldr r1, _08084440 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808449C
	ldr r2, _08084444 @ =0x00000476
	adds r1, r4, r2
	movs r0, #4
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0808444C
	ldr r3, _08084448 @ =0x0000046B
	adds r2, r4, r3
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	adds r7, #0xee
	adds r1, r4, r7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08084490
	mov r0, ip
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08080e0c
	b _0808453A
	.align 2, 0
_08084440: .4byte 0x0000037D
_08084444: .4byte 0x00000476
_08084448: .4byte 0x0000046B
_0808444C:
	ldr r1, _08084488 @ =0x00000469
	adds r2, r4, r1
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r1, r4, r7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08084490
	mov r0, ip
	strb r0, [r2]
	adds r0, r3, #0
	adds r1, r5, #0
	bl FUN_08080f20
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _0808448C @ =0x000003D2
	adds r0, r4, r3
	strb r6, [r0]
	adds r1, r5, #0
	adds r1, #0x40
	movs r0, #0x64
	b _08084538
	.align 2, 0
_08084488: .4byte 0x00000469
_0808448C: .4byte 0x000003D2
_08084490:
	ldr r0, _08084498 @ =0x0000036A
	bl PlaySound_082406e0
	b _0808453A
	.align 2, 0
_08084498: .4byte 0x0000036A
_0808449C:
	ldr r7, _080844C8 @ =0x00000469
	adds r1, r4, r7
	movs r0, #0
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _080844BC
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _080844CC
_080844BC:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r5, #0
	bl FUN_08080f80
	b _0808453A
	.align 2, 0
_080844C8: .4byte 0x00000469
_080844CC:
	adds r0, r3, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r2, _08084500 @ =0x000003E6
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08084504
	adds r0, r3, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r3, #0xfa
	lsls r3, r3, #2
	adds r1, r4, r3
	b _08084538
	.align 2, 0
_08084500: .4byte 0x000003E6
_08084504:
	movs r7, #0x24
	ldrsh r0, [r3, r7]
	movs r2, #0x24
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r7, #0x28
	ldrsh r1, [r3, r7]
	movs r3, #0x28
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	adds r0, #4
	ands r0, r1
	movs r7, #0xfa
	lsls r7, r7, #2
	adds r1, r4, r7
_08084538:
	strh r0, [r1]
_0808453A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
