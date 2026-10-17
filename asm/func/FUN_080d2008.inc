	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D202A
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D202E
_080D202A:
	movs r6, #0x30
	b _080D2030
_080D202E:
	movs r6, #0x40
_080D2030:
	ldr r3, _080D2044 @ =0x0000037D
	adds r4, r5, r3
	ldrb r0, [r4]
	cmp r0, #1
	beq _080D2084
	cmp r0, #1
	bgt _080D2048
	cmp r0, #0
	beq _080D2054
	b _080D21C2
	.align 2, 0
_080D2044: .4byte 0x0000037D
_080D2048:
	cmp r0, #4
	beq _080D20DC
	cmp r0, #6
	bne _080D2052
	b _080D2160
_080D2052:
	b _080D21C2
_080D2054:
	adds r0, r5, #0
	bl FUN_080d1a44
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x15
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl PlayerLink_PlayAnim
	cmp r0, #0
	bne _080D2078
	b _080D21C2
_080D2078:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl PlayerLink_SetAction
	b _080D21C2
_080D2084:
	adds r0, r5, #0
	bl FUN_080d1a44
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x16
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D20CC
	adds r0, r5, #0
	bl FUN_080d1c08
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl PlayerLink_SetAction
	b _080D21C2
_080D20CC:
	ldr r0, _080D20D8 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080D21C2
	.align 2, 0
_080D20D8: .4byte 0x0000037E
_080D20DC:
	ldr r2, _080D2158 @ =0x000003D1
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D20FE
	ldr r0, _080D215C @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D20FE:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r4, r5, r1
	ldrb r0, [r4]
	movs r1, #0x17
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl PlayerLink_PlayAnim
	ldrb r0, [r4]
	cmp r0, #1
	bne _080D2142
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #2
	bne _080D2142
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D2142
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	bl FUN_080ccb20
_080D2142:
	adds r0, r5, #0
	bl FUN_080d1e7c
	cmp r0, #0
	beq _080D21C2
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl PlayerLink_SetAction
	b _080D21C2
	.align 2, 0
_080D2158: .4byte 0x000003D1
_080D215C: .4byte 0x00000A76
_080D2160:
	ldr r3, _080D2194 @ =0x000003D1
	adds r0, r5, r3
	movs r3, #0
	strb r3, [r0]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D2182
	ldr r2, _080D2198 @ =0x00000A76
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_080D2182:
	ldr r0, _080D2198 @ =0x00000A76
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D219C
	strb r3, [r2]
	strb r3, [r4]
	b _080D21C2
	.align 2, 0
_080D2194: .4byte 0x000003D1
_080D2198: .4byte 0x00000A76
_080D219C:
	ldr r1, _080D21C8 @ =0x0000037E
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldr r3, _080D21CC @ =0x00000A88
	adds r0, r5, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	blo _080D21C2
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
_080D21C2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D21C8: .4byte 0x0000037E
_080D21CC: .4byte 0x00000A88
