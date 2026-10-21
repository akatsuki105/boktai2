	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r0, #0x9c
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _080D08CE
	b _080D09F8
_080D08CE:
	adds r0, r4, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D08DA
	b _080D09F8
_080D08DA:
	ldr r1, _080D093C @ =0x00000446
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0
	adds r5, r0, #0
	cmp r1, #0
	beq _080D08F4
	ldr r1, _080D0940 @ =0x00000442
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D08F4
	movs r2, #1
_080D08F4:
	cmp r2, #0
	beq _080D08FA
	b _080D09F8
_080D08FA:
	movs r2, #0xe5
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	bl PlayerLink_IsLiveLava
	cmp r0, #0
	beq _080D0960
	ldrh r0, [r5]
	movs r2, #0
	cmp r0, #0
	beq _080D091E
	ldr r1, _080D0940 @ =0x00000442
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D091E
	movs r2, #1
_080D091E:
	cmp r2, #0
	bne _080D0960
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D0944
	adds r1, r4, #0
	adds r1, #0x2c
	str r1, [sp]
	str r2, [sp, #4]
	movs r0, #0xca
	lsls r0, r0, #1
	b _080D094E
	.align 2, 0
_080D093C: .4byte 0x00000446
_080D0940: .4byte 0x00000442
_080D0944:
	adds r1, r4, #0
	adds r1, #0x2c
	str r1, [sp]
	str r2, [sp, #4]
	ldr r0, _080D095C @ =0x00000193
_080D094E:
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #1
	bl FUN_080d03bc
	b _080D09F8
	.align 2, 0
_080D095C: .4byte 0x00000193
_080D0960:
	cmp r6, #0
	bne _080D09F8
	ldrh r0, [r5]
	movs r1, #0
	cmp r0, #0
	beq _080D0978
	ldr r2, _080D0990 @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D0978
	movs r1, #1
_080D0978:
	cmp r1, #0
	beq _080D099E
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D0994
	ldr r0, [r4, #0x18]
	movs r1, #0xc8
	bl Sound_PlayForPlayer
	b _080D09F8
	.align 2, 0
_080D0990: .4byte 0x00000442
_080D0994:
	ldr r0, [r4, #0x18]
	movs r1, #0xc7
	bl Sound_PlayForPlayer
	b _080D09F8
_080D099E:
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D09B4
	ldr r2, _080D09C8 @ =0x000001C7
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D09D6
_080D09B4:
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D09CC
	ldr r0, [r4, #0x18]
	movs r1, #0xca
	bl Sound_PlayForPlayer
	b _080D09F8
	.align 2, 0
_080D09C8: .4byte 0x000001C7
_080D09CC:
	ldr r0, [r4, #0x18]
	movs r1, #0xc9
	bl Sound_PlayForPlayer
	b _080D09F8
_080D09D6:
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D09F0
	ldr r0, [r4, #0x18]
	ldr r1, _080D09EC @ =0x0000028E
	bl Sound_PlayForPlayer
	b _080D09F8
	.align 2, 0
_080D09EC: .4byte 0x0000028E
_080D09F0:
	ldr r0, [r4, #0x18]
	ldr r1, _080D0A00 @ =0x0000028D
	bl Sound_PlayForPlayer
_080D09F8:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D0A00: .4byte 0x0000028D
