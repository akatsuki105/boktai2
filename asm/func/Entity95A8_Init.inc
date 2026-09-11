	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	adds r7, r0, #0
	movs r4, #0
	strh r1, [r7, #0x18]
	movs r0, #0x6c
	movs r1, #0xc8
	bl VM_GetKeywordValue
	strh r0, [r7, #0x26]
	movs r0, #1
	strh r0, [r7, #0x24]
	strh r4, [r7, #0x28]
	movs r0, #0x6e
	movs r1, #4
	bl VM_GetKeywordValue
	strh r0, [r7, #0x36]
	movs r0, #0x65
	movs r1, #0x32
	bl VM_GetKeywordValue
	strh r0, [r7, #0x38]
	strh r4, [r7, #0x2a]
	strh r4, [r7, #0x2c]
	strh r4, [r7, #0x2e]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800C2E8
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800C2E0 @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	bl Script_GetValue
	adds r0, #0x64
	lsls r0, r0, #0x10
	ldr r2, _0800C2E4 @ =0x0000FFFF
	ldr r1, [sp, #0xc]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0xc]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	b _0800C2F2
	.align 2, 0
_0800C2E0: .4byte 0xFFFF0000
_0800C2E4: .4byte 0x0000FFFF
_0800C2E8:
	ldr r1, _0800C3AC @ =0xFFFF0000
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r1
	str r0, [sp, #0x10]
_0800C2F2:
	add r4, sp, #0xc
	adds r0, r4, #0
	bl FUN_08241574
	str r0, [r7, #0x20]
	adds r0, r7, #0
	adds r0, #0x30
	movs r6, #0
	strb r6, [r0]
	ldrh r0, [r4, #2]
	strh r0, [r7, #0x32]
	strh r6, [r7, #0x34]
	ldr r2, _0800C3AC @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r4, #0x1e
	orrs r0, r4
	ldr r1, _0800C3B0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	movs r0, #0xa0
	lsls r0, r0, #0x10
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r7, #0
	adds r4, #0xc4
	ldr r2, _0800C3B4 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _0800C3B8 @ =FUN_0800c0b0
	adds r0, r4, #0
	adds r2, r7, #0
	bl FUN_0823651c
	adds r0, r4, #0
	add r1, sp, #0xc
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	subs r4, #0x88
	ldr r1, _0800C3BC @ =0x0000066A
	adds r0, r4, #0
	bl Video_GetActorSprite
	adds r5, r7, #0
	adds r5, #0x58
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	strh r6, [r5, #0x10]
	ldr r1, _0800C3C0 @ =0x00000169
	adds r0, r4, #0
	bl Video_SetActorSpritePltt
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r7, #0x74]
	str r1, [r7, #0x78]
	adds r0, r7, #0
	adds r0, #0x84
	adds r1, r7, #0
	adds r1, #0x74
	movs r2, #0
	bl FUN_0801385c
	movs r0, #0
	add sp, #0x24
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800C3AC: .4byte 0xFFFF0000
_0800C3B0: .4byte 0x0000FFFF
_0800C3B4: .4byte 0x00004001
_0800C3B8: .4byte FUN_0800c0b0
_0800C3BC: .4byte 0x0000066A
_0800C3C0: .4byte 0x00000169
