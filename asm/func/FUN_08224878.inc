	push {r4, r5, lr}
	sub sp, #4
	ldr r0, _0822494C @ =0x03000248
	ldr r4, [r0]
	cmp r4, #0
	bne _08224892
	ldr r0, _08224950 @ =0x0000BB34
	movs r1, #0
	bl Entity8AAB_Create
	adds r4, r0, #0
	cmp r4, #0
	beq _08224944
_08224892:
	bl Script_GetValue
	ldr r2, _08224954 @ =0x00000F46
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	lsls r0, r0, #0x18
	movs r5, #0
	movs r1, #0xe0
	lsls r1, r1, #0x13
	ands r1, r0
	lsrs r1, r1, #0x18
	ldr r2, _08224958 @ =0x00000F24
	adds r0, r4, r2
	strb r1, [r0]
	cmp r1, #4
	bls _082248C4
	movs r0, #8
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r5, #1
_082248C4:
	ldr r0, _0822495C @ =0x00000F22
	adds r3, r4, r0
	strb r1, [r3]
	ldr r1, _08224960 @ =0x00000F27
	adds r2, r4, r1
	strb r5, [r2]
	ldr r5, _08224964 @ =0x00000DE4
	adds r0, r4, r5
	adds r5, #0x50
	adds r1, r4, r5
	ldr r1, [r1]
	ldrb r3, [r3]
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #0
	bl FUN_08236fac
	ldr r0, _08224968 @ =0x00000F16
	adds r5, r4, r0
	ldrb r0, [r5]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _0822496C @ =0x00000F18
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
	strh r0, [r5]
	ldrh r0, [r3]
	cmp r0, #3
	bne _08224936
	ldrb r1, [r5]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _08224936
	ldr r2, _08224970 @ =0x00000DEC
	adds r0, r4, r2
	ldrh r1, [r0]
	ldr r5, _08224974 @ =0x00000F42
	adds r0, r4, r5
	strb r1, [r0]
	ldr r1, _08224978 @ =0x00000DF2
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _0822497C @ =0x00000F43
	adds r0, r4, r2
	strb r1, [r0]
_08224936:
	movs r0, #1
	movs r5, #0xf2
	lsls r5, r5, #4
	adds r2, r4, r5
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_08224944:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0822494C: .4byte 0x03000248
_08224950: .4byte 0x0000BB34
_08224954: .4byte 0x00000F46
_08224958: .4byte 0x00000F24
_0822495C: .4byte 0x00000F22
_08224960: .4byte 0x00000F27
_08224964: .4byte 0x00000DE4
_08224968: .4byte 0x00000F16
_0822496C: .4byte 0x00000F18
_08224970: .4byte 0x00000DEC
_08224974: .4byte 0x00000F42
_08224978: .4byte 0x00000DF2
_0822497C: .4byte 0x00000F43
