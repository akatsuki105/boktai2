	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #2
	bne _080D6EB8
	b _080D71EC
_080D6EB8:
	cmp r0, #2
	bhi _080D6EC2
	cmp r0, #1
	beq _080D6ECA
	b _080D7208
_080D6EC2:
	cmp r0, #8
	bne _080D6EC8
	b _080D71A8
_080D6EC8:
	b _080D7208
_080D6ECA:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080D6EF4
	ldr r1, [r5, #0x18]
	ldr r0, _080D6EE0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D6EE4
	movs r0, #0
	b _080D6EEA
	.align 2, 0
_080D6EE0: .4byte 0x03002C68
_080D6EE4:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080D6EEA:
	adds r1, r0, #1
	asrs r1, r1, #1
	adds r0, r5, #0
	bl FUN_080d0394
_080D6EF4:
	adds r0, r5, #0
	bl FUN_080d6600
	adds r0, r5, #0
	bl FUN_080d6804
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080cfaa4
	ldr r1, _080D7004 @ =0x085AD204
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D6F32
	movs r2, #0xea
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_080D6F32:
	adds r0, r5, #0
	bl FUN_080d69dc
	ldr r4, _080D7008 @ =0x000003CE
	adds r0, r5, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080D6F4A
	adds r0, r5, #0
	bl FUN_080cfb20
_080D6F4A:
	adds r0, r5, #0
	bl FUN_080cfcb0
	adds r0, r5, #0
	bl FUN_080d01c8
	ldr r2, _080D700C @ =0x00000446
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D6F6E
	ldr r4, _080D7010 @ =0x00000442
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D6F6E
	movs r1, #1
_080D6F6E:
	cmp r1, #0
	beq _080D6F74
	b _080D7208
_080D6F74:
	movs r4, #0
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	bl FUN_080cfc78
	cmp r0, #0
	bne _080D6FB2
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r2, [r0]
	cmp r2, #1
	bne _080D6FB2
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080D6FB2
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r1, [r0]
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r4, r0, #0x1f
_080D6FB2:
	cmp r4, #0
	bne _080D6FB8
	b _080D719C
_080D6FB8:
	ldr r0, _080D7014 @ =0x000003BE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	beq _080D6FCC
	b _080D7208
_080D6FCC:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D7018 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080D701C
	asrs r2, r0, #0xc
	b _080D7022
	.align 2, 0
_080D7004: .4byte 0x085AD204
_080D7008: .4byte 0x000003CE
_080D700C: .4byte 0x00000446
_080D7010: .4byte 0x00000442
_080D7014: .4byte 0x000003BE
_080D7018: .4byte gSineTable
_080D701C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D7022:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D704C @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _080D7050
	asrs r2, r0, #0xc
	b _080D7056
	.align 2, 0
_080D704C: .4byte 0xFFFF0000
_080D7050:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D7056:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D7098 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D7092
	cmp r1, #0
	blt _080D7092
	ldr r0, _080D709C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D7092
	ldr r0, _080D70A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D70A4
_080D7092:
	movs r4, #0
	b _080D70B2
	.align 2, 0
_080D7098: .4byte 0xFFFF0000
_080D709C: .4byte 0x030046A8
_080D70A0: .4byte 0x030046AC
_080D70A4:
	ldr r0, _080D70C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D70B2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080D70C8
	adds r0, #4
	b _080D70D4
	.align 2, 0
_080D70C4: .4byte 0x030046A4
_080D70C8:
	ldr r0, _080D70E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D70D4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080D70EC
	cmp r2, #2
	beq _080D70F0
	b _080D70F4
	.align 2, 0
_080D70E8: .4byte 0x030046A4
_080D70EC:
	ldrb r0, [r6, #4]
	b _080D70F2
_080D70F0:
	ldrb r0, [r6]
_080D70F2:
	subs r1, r1, r0
_080D70F4:
	movs r4, #0x2e
	ldrsh r0, [r5, r4]
	adds r0, #0xc8
	cmp r1, r0
	bhs _080D7100
	b _080D7208
_080D7100:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D7128
	cmp r1, #0
	blt _080D7128
	ldr r0, _080D712C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D7128
	ldr r0, _080D7130 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D7134
_080D7128:
	movs r4, #0
	b _080D7142
	.align 2, 0
_080D712C: .4byte 0x030046A8
_080D7130: .4byte 0x030046AC
_080D7134:
	ldr r0, _080D7154 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D7142:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080D7158
	adds r0, #4
	b _080D7164
	.align 2, 0
_080D7154: .4byte 0x030046A4
_080D7158:
	ldr r0, _080D7194 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D7164:
	ldrh r2, [r0, #2]
	movs r3, #4
	ands r2, r3
	cmp r2, #0
	bne _080D7208
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r4, _080D7198 @ =0x000003BD
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	subs r4, #0x41
	adds r0, r5, r4
	strb r3, [r0]
	subs r1, #0x3f
	adds r0, r5, r1
	strb r2, [r0]
	b _080D7208
	.align 2, 0
_080D7194: .4byte 0x030046A4
_080D7198: .4byte 0x000003BD
_080D719C:
	ldr r2, _080D71A4 @ =0x000003BE
	adds r0, r5, r2
	strh r4, [r0]
	b _080D7208
	.align 2, 0
_080D71A4: .4byte 0x000003BE
_080D71A8:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r1, r5, r4
	ldrb r0, [r1]
	cmp r0, #0x1c
	bne _080D71C0
	adds r4, r0, #0
	b _080D71CE
_080D71C0:
	ldr r1, _080D71E4 @ =0x000003D2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r4, #0x1a
	cmp r0, #0
	beq _080D71CE
	movs r4, #0x1b
_080D71CE:
	ldr r0, _080D71E8 @ =0x085AD204
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_080d69dc
	b _080D7208
	.align 2, 0
_080D71E4: .4byte 0x000003D2
_080D71E8: .4byte 0x085AD204
_080D71EC:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_080d69dc
_080D7208:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
