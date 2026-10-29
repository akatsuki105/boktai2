	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	adds r2, r6, #0
	adds r2, #0x76
	ldrb r0, [r2]
	cmp r0, #0
	beq _081F2014
	movs r1, #0
	strb r1, [r2]
	adds r0, r6, #0
	adds r0, #0x74
	strh r1, [r0]
_081F2014:
	adds r2, r6, #0
	adds r2, #0x6c
	ldrh r1, [r2]
	movs r0, #8
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	beq _081F2118
	mov ip, r6
	mov r0, ip
	adds r0, #4
	mov ip, r0
	subs r0, #4
	ldm r0!, {r4}
	ldrh r0, [r0, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	mov r1, ip
	ldrb r0, [r1, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F205E
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _081F2066
_081F205E:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F2066:
	str r0, [r4]
	mov r2, ip
	ldrb r0, [r2, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F208C
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _081F2094
_081F208C:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F2094:
	str r0, [r4]
	mov r3, ip
	ldrh r0, [r3, #0xe]
	adds r0, #1
	strh r0, [r3, #0xe]
	ldr r1, _081F20D4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r3, #7]
	cmp r0, r3
	bhs _081F20AE
	b _081F220E
_081F20AE:
	movs r0, #0
	mov r1, ip
	strh r0, [r1, #0xe]
	ldrb r1, [r1, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F20E0
	mov r2, ip
	ldrh r0, [r2, #8]
	cmp r0, #0
	bne _081F20D8
	ldrb r0, [r2, #5]
	subs r0, #1
	strh r0, [r2, #8]
	b _081F20F2
	.align 2, 0
_081F20D4: .4byte 0x0000FFFF
_081F20D8:
	subs r0, #1
	mov r3, ip
	strh r0, [r3, #8]
	b _081F20F2
_081F20E0:
	mov r3, ip
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _081F20F2
	strh r1, [r3, #8]
_081F20F2:
	mov r3, ip
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F220E
	movs r0, #1
	b _081F220C
_081F2118:
	mov ip, r6
	mov r0, ip
	adds r0, #4
	mov ip, r0
	subs r0, #4
	ldm r0!, {r4}
	ldr r3, [r4, #0x28]
	ldrh r0, [r0, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #4]
	adds r5, r1, r0
	ldrh r2, [r5]
	lsrs r2, r2, #6
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r4, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r4, #8]
	mov r1, ip
	ldrb r0, [r1, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F2164
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _081F216C
_081F2164:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F216C:
	str r0, [r4]
	mov r2, ip
	ldrb r0, [r2, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F2192
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _081F219A
_081F2192:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F219A:
	str r0, [r4]
	mov r3, ip
	ldrh r0, [r3, #0xe]
	adds r0, #1
	strh r0, [r3, #0xe]
	ldr r1, _081F21D8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r3, #7]
	cmp r0, r3
	blo _081F220E
	movs r0, #0
	mov r1, ip
	strh r0, [r1, #0xe]
	ldrb r1, [r1, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F21E4
	mov r2, ip
	ldrh r0, [r2, #8]
	cmp r0, #0
	bne _081F21DC
	ldrb r0, [r2, #5]
	subs r0, #1
	strh r0, [r2, #8]
	b _081F21F6
	.align 2, 0
_081F21D8: .4byte 0x0000FFFF
_081F21DC:
	subs r0, #1
	mov r3, ip
	strh r0, [r3, #8]
	b _081F21F6
_081F21E4:
	mov r3, ip
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _081F21F6
	strh r1, [r3, #8]
_081F21F6:
	mov r3, ip
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
_081F220C:
	strb r0, [r3, #7]
_081F220E:
	ldrh r1, [r7]
	movs r0, #8
	ands r0, r1
	ldr r0, [r6]
	adds r4, r6, #0
	adds r4, #0x74
	ldrh r1, [r4]
	movs r2, #0x3c
	movs r3, #0x28
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081F228E
	ldr r0, _081F226C @ =0x030001EC
	ldr r2, [r0]
	adds r3, r6, #0
	adds r3, #0x6f
	movs r0, #0
	ldrsb r0, [r3, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2, #0x18]
	bics r0, r1
	str r0, [r2, #0x18]
	adds r1, r6, #0
	adds r1, #0x6e
	movs r0, #0
	strb r0, [r1]
	ldrh r1, [r7]
	movs r0, #8
	ands r0, r1
	adds r4, r3, #0
	cmp r0, #0
	beq _081F2270
	ldr r1, [r6]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F2284
	adds r0, r1, #0
	bl AuxSprite_Remove
	ldr r0, [r6]
	bl Free
	b _081F2284
	.align 2, 0
_081F226C: .4byte 0x030001EC
_081F2270:
	ldr r1, [r6]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F2284
	adds r0, r1, #0
	bl Particle_Remove
	ldr r0, [r6]
	bl Free
_081F2284:
	movs r0, #0xff
	strb r0, [r4]
	movs r0, #0
	strh r0, [r7]
	b _081F2294
_081F228E:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_081F2294:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
