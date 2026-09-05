	push {r4, r5, lr}
	ldr r0, _082245E0 @ =0x03000248
	ldr r4, [r0]
	cmp r4, #0
	bne _082245A8
	ldr r0, _082245E4 @ =0x0000BB34
	movs r1, #0
	bl Entity8AAB_Create
	adds r4, r0, #0
	cmp r4, #0
	beq _08224694
_082245A8:
	bl Script_GetValue
	ldr r2, _082245E8 @ =0x00000F46
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _082245F4
	bl Script_GetValue
	ldr r2, _082245EC @ =0x00000E8C
	adds r1, r4, r2
	strh r0, [r1]
	bl Script_GetValue
	adds r0, #0xa0
	ldr r2, _082245F0 @ =0x00000E8E
	adds r1, r4, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xe9
	lsls r2, r2, #4
	adds r1, r4, r2
	strh r0, [r1]
	b _08224614
	.align 2, 0
_082245E0: .4byte 0x03000248
_082245E4: .4byte 0x0000BB34
_082245E8: .4byte 0x00000F46
_082245EC: .4byte 0x00000E8C
_082245F0: .4byte 0x00000E8E
_082245F4:
	ldr r0, [r4, #0x18]
	ldrh r1, [r0, #0x2c]
	ldr r2, _0822469C @ =0x00000E8C
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, [r4, #0x18]
	ldrh r0, [r0, #0x2e]
	adds r0, #0xa0
	adds r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	ldr r0, [r4, #0x18]
	ldrh r1, [r0, #0x30]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
_08224614:
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x64
	bl VM_GetKeywordValue
	ldr r2, _082246A0 @ =0x00000F23
	adds r1, r4, r2
	strb r0, [r1]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _082246A4 @ =0x00000F0C
	adds r1, r4, r2
	str r0, [r1]
	ldr r0, _082246A8 @ =0x00000F16
	adds r5, r4, r0
	ldrb r0, [r5]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _082246AC @ =0x00000F18
	adds r3, r4, r1
	strh r0, [r3]
	movs r2, #2
	ldrb r1, [r5]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	ldrh r1, [r5]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0xa0
	orrs r0, r1
	strh r0, [r5]
	ldrh r0, [r3]
	cmp r0, #3
	bne _08224686
	ldrb r1, [r5]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _08224686
	ldr r2, _082246B0 @ =0x00000DEC
	adds r0, r4, r2
	ldrh r1, [r0]
	ldr r2, _082246B4 @ =0x00000F42
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _082246B8 @ =0x00000DF2
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
_08224686:
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r4, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_08224694:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0822469C: .4byte 0x00000E8C
_082246A0: .4byte 0x00000F23
_082246A4: .4byte 0x00000F0C
_082246A8: .4byte 0x00000F16
_082246AC: .4byte 0x00000F18
_082246B0: .4byte 0x00000DEC
_082246B4: .4byte 0x00000F42
_082246B8: .4byte 0x00000DF2
