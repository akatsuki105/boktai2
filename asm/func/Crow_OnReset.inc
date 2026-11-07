	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0814427C @ =0x0000065C
	adds r0, r6, r2
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08144280 @ =0x00000672
	adds r0, r6, r3
	strb r1, [r0]
	adds r2, #0x17
	adds r0, r6, r2
	strb r1, [r0]
	subs r3, #0x11
	adds r0, r6, r3
	strb r1, [r0]
	subs r2, #0xb
	adds r0, r6, r2
	strb r1, [r0]
	subs r3, #9
	adds r0, r6, r3
	str r1, [r0]
	movs r0, #0xd7
	lsls r0, r0, #3
	adds r2, r6, r0
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #8]
	str r1, [r5, #0xc]
	ldr r1, _08144284 @ =0x0000066C
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r3, _08144288 @ =0x00000256
	adds r0, r5, r3
	strh r1, [r0]
	ldrh r4, [r0]
	adds r7, r2, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0814428C
	adds r0, #4
	b _08144298
	.align 2, 0
_0814427C: .4byte 0x0000065C
_08144280: .4byte 0x00000672
_08144284: .4byte 0x0000066C
_08144288: .4byte 0x00000256
_0814428C:
	ldr r0, _081442AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08144298:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081442B0
	cmp r3, #2
	beq _081442B4
	b _081442B8
	.align 2, 0
_081442AC: .4byte 0x030046A4
_081442B0:
	ldrb r0, [r7, #4]
	b _081442B6
_081442B4:
	ldrb r0, [r7]
_081442B6:
	subs r2, r2, r0
_081442B8:
	ldr r0, _081442E4 @ =0x00000472
	adds r1, r5, r0
	strh r2, [r1]
	ldrh r0, [r5, #0xa]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r2, r5, r3
	strh r0, [r2]
	ldrh r0, [r1]
	strh r0, [r5, #0xa]
	ldr r1, _081442E8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081442EC
	ldr r2, [r5, #0x44]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _081442F6
	.align 2, 0
_081442E4: .4byte 0x00000472
_081442E8: .4byte 0x0000025D
_081442EC:
	ldr r2, [r5, #0x44]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_081442F6:
	movs r2, #0xd4
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r4, #0
	str r4, [sp]
	mov r0, sp
	ldr r2, _08144364 @ =0x05000002
	bl CpuSet
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r1, r6, r3
	str r4, [sp]
	mov r0, sp
	ldr r2, _08144364 @ =0x05000002
	bl CpuSet
	movs r0, #0xd6
	lsls r0, r0, #3
	adds r1, r6, r0
	str r4, [sp]
	mov r0, sp
	ldr r2, _08144364 @ =0x05000002
	bl CpuSet
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r5, [r5, #0x44]
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08144368
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08144370
	.align 2, 0
_08144364: .4byte 0x05000002
_08144368:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08144370:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08144394
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0814439C
_08144394:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0814439C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081443D4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0814440C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081443D8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081443CC
	ldrb r0, [r4, #5]
_081443CC:
	subs r0, #1
	strh r0, [r4, #8]
	b _081443E8
	.align 2, 0
_081443D4: .4byte 0x0000FFFF
_081443D8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081443E8
	strh r1, [r4, #8]
_081443E8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814440C
	movs r0, #1
	strb r0, [r4, #7]
_0814440C:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
