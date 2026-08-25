	push {r4, r5, lr}
	ldr r0, _08224BD8 @ =0x03000248
	ldr r4, [r0]
	cmp r4, #0
	bne _08224BAC
	ldr r0, _08224BDC @ =0x0000BB34
	movs r1, #0
	bl Entity8AAB_Create
	adds r4, r0, #0
	cmp r4, #0
	beq _08224C6E
_08224BAC:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08224BEC
	bl Script_GetValue
	ldr r2, _08224BE0 @ =0x00000DB8
	adds r1, r4, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08224BE4 @ =0x00000DBA
	adds r1, r4, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08224BE8 @ =0x00000DBC
	adds r1, r4, r2
	strh r0, [r1]
	b _08224C0C
	.align 2, 0
_08224BD8: .4byte 0x03000248
_08224BDC: .4byte 0x0000BB34
_08224BE0: .4byte 0x00000DB8
_08224BE4: .4byte 0x00000DBA
_08224BE8: .4byte 0x00000DBC
_08224BEC:
	ldr r0, [r4, #0x18]
	ldrh r1, [r0, #0x2c]
	ldr r2, _08224C74 @ =0x00000DB8
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
_08224C0C:
	ldr r0, _08224C78 @ =0x00000F16
	adds r5, r4, r0
	ldrb r0, [r5]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _08224C7C @ =0x00000F18
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
	movs r1, #0xe0
	orrs r0, r1
	strh r0, [r5]
	ldrh r0, [r3]
	cmp r0, #3
	bne _08224C60
	ldrb r1, [r5]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _08224C60
	ldr r2, _08224C80 @ =0x00000DEC
	adds r0, r4, r2
	ldrh r1, [r0]
	ldr r2, _08224C84 @ =0x00000F42
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _08224C88 @ =0x00000DF2
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
_08224C60:
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r4, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_08224C6E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08224C74: .4byte 0x00000DB8
_08224C78: .4byte 0x00000F16
_08224C7C: .4byte 0x00000F18
_08224C80: .4byte 0x00000DEC
_08224C84: .4byte 0x00000F42
_08224C88: .4byte 0x00000DF2
