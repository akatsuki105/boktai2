	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r6, [r5, #0x44]
	ldr r2, _0819C808 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819C80C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819C80E
	.align 2, 0
_0819C808: .4byte 0x0000046D
_0819C80C:
	movs r0, #0
_0819C80E:
	cmp r0, #0
	beq _0819C846
	ldr r0, [r6]
	movs r1, #2
	orrs r0, r1
	str r0, [r6]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _0819C854 @ =0x00000ECF
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0819C858 @ =0x00000F14
	adds r2, r4, r0
	ldr r0, _0819C85C @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _0819C860 @ =0x00000ECC
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0819C864 @ =0x0000016F
	bl PlaySound_082406e0
_0819C846:
	ldrb r1, [r6, #6]
	cmp r1, #0x80
	ble _0819C86C
	ldr r0, _0819C868 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0819C87A
	.align 2, 0
_0819C854: .4byte 0x00000ECF
_0819C858: .4byte 0x00000F14
_0819C85C: .4byte 0x03002BE0
_0819C860: .4byte 0x00000ECC
_0819C864: .4byte 0x0000016F
_0819C868: .4byte 0xFFFFFF00
_0819C86C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819C87A
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0819C87A:
	adds r0, r1, #0
	cmp r0, #0
	bge _0819C882
	rsbs r0, r0, #0
_0819C882:
	cmp r0, #0x30
	ble _0819C900
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _0819C8B0 @ =0x00000546
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0819C8BC
	ldr r1, _0819C8B4 @ =0x00000E3E
	adds r0, r4, r1
	ldrb r0, [r0]
	lsrs r0, r0, #1
	cmp r7, r0
	ble _0819C96E
	ldr r4, _0819C8B8 @ =FUN_0819c974
	movs r3, #0x35
	subs r2, #0xd9
	adds r1, r5, r2
	b _0819C8CE
	.align 2, 0
_0819C8B0: .4byte 0x00000546
_0819C8B4: .4byte 0x00000E3E
_0819C8B8: .4byte FUN_0819c974
_0819C8BC:
	ldr r2, _0819C8F0 @ =0x00000E3E
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r7, r0
	ble _0819C96E
	ldr r4, _0819C8F4 @ =FUN_0819c974
	movs r3, #0x35
	ldr r0, _0819C8F8 @ =0x0000046D
	adds r1, r5, r0
_0819C8CE:
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819C8FC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	b _0819C96E
	.align 2, 0
_0819C8F0: .4byte 0x00000E3E
_0819C8F4: .4byte FUN_0819c974
_0819C8F8: .4byte 0x0000046D
_0819C8FC: .4byte 0x0000046B
_0819C900:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _0819C91C @ =0x00000546
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0819C924
	ldr r1, _0819C920 @ =0x00000E3F
	adds r0, r4, r1
	ldrb r2, [r0]
	b _0819C92C
	.align 2, 0
_0819C91C: .4byte 0x00000546
_0819C920: .4byte 0x00000E3F
_0819C924:
	ldr r2, _0819C944 @ =0x00000E3F
	adds r0, r4, r2
	ldrb r0, [r0]
	lsrs r2, r0, #1
_0819C92C:
	cmp r2, #0
	bgt _0819C932
	movs r2, #1
_0819C932:
	ldr r1, _0819C948 @ =0x00000ECF
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x20
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0819C950
	ldr r0, _0819C94C @ =0xFFFFFF00
	b _0819C95C
	.align 2, 0
_0819C944: .4byte 0x00000E3F
_0819C948: .4byte 0x00000ECF
_0819C94C: .4byte 0xFFFFFF00
_0819C950:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819C95E
	movs r0, #0x80
	lsls r0, r0, #1
_0819C95C:
	adds r1, r1, r0
_0819C95E:
	cmp r1, #0
	bge _0819C968
	ldrb r0, [r6, #6]
	subs r0, r0, r2
	b _0819C96C
_0819C968:
	ldrb r0, [r6, #6]
	adds r0, r0, r2
_0819C96C:
	strb r0, [r6, #6]
_0819C96E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
