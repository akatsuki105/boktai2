	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _0801B0D8 @ =0x03000094
	str r5, [r0]
	movs r0, #0
	strh r0, [r5, #0x20]
	strh r0, [r5, #0x22]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r5, #0x1a]
	movs r0, #0x72
	movs r1, #0xfa
	bl VM_GetKeywordValue
	lsls r1, r0, #4
	strh r1, [r5, #0x18]
	lsls r0, r0, #0x14
	ldr r1, _0801B0DC @ =0x0F9F0000
	cmp r0, r1
	ble _0801B092
	movs r0, #0xfa
	lsls r0, r0, #4
	strh r0, [r5, #0x18]
_0801B092:
	movs r0, #0x73
	movs r1, #8
	bl VM_GetKeywordValue
	lsls r0, r0, #4
	strh r0, [r5, #0x1c]
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r5, #0x1e]
	ldr r0, _0801B0E0 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801B174
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r6, r5, r1
	adds r7, r0, #0
	adds r7, #0x2c
	ldrh r0, [r0, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801B0E4
	asrs r0, r0, #8
	b _0801B0EA
	.align 2, 0
_0801B0D8: .4byte 0x03000094
_0801B0DC: .4byte 0x0F9F0000
_0801B0E0: .4byte 0x03002BE0
_0801B0E4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801B0EA:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801B0FC
	asrs r0, r0, #8
	b _0801B102
_0801B0FC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801B102:
	adds r4, r0, #0
	movs r2, #2
	ldrsh r1, [r7, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0801B116
	asrs r0, r0, #8
	b _0801B11C
_0801B116:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801B11C:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0801B14C @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0801B150
	movs r0, #0
	b _0801B156
	.align 2, 0
_0801B14C: .4byte 0x030047C8
_0801B150:
	cmp r0, #0xf0
	ble _0801B158
	movs r0, #0xf0
_0801B156:
	strh r0, [r1]
_0801B158:
	ldr r0, _0801B168 @ =0x000002F6
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0801B16C
	movs r0, #0
	b _0801B184
	.align 2, 0
_0801B168: .4byte 0x000002F6
_0801B16C:
	cmp r0, #0xb4
	ble _0801B186
	movs r0, #0xb4
	b _0801B184
_0801B174:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0x78
	strh r0, [r1]
	ldr r2, _0801B19C @ =0x000002F6
	adds r1, r5, r2
	movs r0, #0x5a
_0801B184:
	strh r0, [r1]
_0801B186:
	movs r4, #0
_0801B188:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0801ad78
	adds r4, #1
	cmp r4, #1
	ble _0801B188
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801B19C: .4byte 0x000002F6
