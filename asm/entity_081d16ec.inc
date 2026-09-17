	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081d0e74
FUN_081d0e74: @ 0x081D0E74
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, #0xb6
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d0e84
FUN_081d0e84: @ 0x081D0E84
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, #0xb6
	ldrh r2, [r0]
	bics r2, r1
	strh r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d0e94
FUN_081d0e94: @ 0x081D0E94
	push {lr}
	adds r0, #0xb6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081D0EA4
	movs r0, #0
	b _081D0EA6
_081D0EA4:
	movs r0, #1
_081D0EA6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d0eac
FUN_081d0eac: @ 0x081D0EAC
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r5, #0
	ldr r0, _081D0EC8 @ =0x0000097C
	adds r2, r3, r0
	movs r6, #1
_081D0EB8:
	adds r1, r6, #0
	lsls r1, r5
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D0ECC
	movs r0, #1
	b _081D0ECE
	.align 2, 0
_081D0EC8: .4byte 0x0000097C
_081D0ECC:
	movs r0, #0
_081D0ECE:
	cmp r0, #0
	bne _081D0EF8
	movs r0, #0xc8
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x1c
	adds r4, r3, r4
	adds r1, r6, #0
	lsls r1, r5
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	movs r1, #0xc8
	bl ClearMemory
	adds r0, r4, #0
	adds r0, #0xb4
	strh r5, [r0]
	adds r0, r4, #0
	b _081D0F00
_081D0EF8:
	adds r5, #1
	cmp r5, #0xb
	ble _081D0EB8
	movs r0, #0
_081D0F00:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d0f08
FUN_081d0f08: @ 0x081D0F08
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081D0F18 @ =0x0300018C
	ldr r1, [r0]
	cmp r1, #0
	bne _081D0F20
	b _081D0F5A
	.align 2, 0
_081D0F18: .4byte 0x0300018C
_081D0F1C:
	adds r0, r1, #0
	b _081D0F5C
_081D0F20:
	movs r3, #0
	ldr r2, _081D0F40 @ =0x0000097C
	adds r0, r1, r2
	ldr r4, [r0]
	movs r6, #1
	adds r2, r1, #0
	adds r2, #0xda
	adds r1, #0x1c
_081D0F30:
	adds r0, r6, #0
	lsls r0, r3
	ands r0, r4
	cmp r0, #0
	beq _081D0F44
	movs r0, #1
	b _081D0F46
	.align 2, 0
_081D0F40: .4byte 0x0000097C
_081D0F44:
	movs r0, #0
_081D0F46:
	cmp r0, #0
	beq _081D0F50
	ldrh r0, [r2]
	cmp r0, r5
	beq _081D0F1C
_081D0F50:
	adds r2, #0xc8
	adds r1, #0xc8
	adds r3, #1
	cmp r3, #0xb
	ble _081D0F30
_081D0F5A:
	movs r0, #0
_081D0F5C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d0f64
FUN_081d0f64: @ 0x081D0F64
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _081D105C @ =0x0300018C
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _081D0F86
	bl Entity081d16ec_Create
	mov sb, r0
	cmp r0, #0
	bne _081D0F86
	b _081D11A6
_081D0F86:
	mov r0, sb
	bl FUN_081d0eac
	adds r6, r0, #0
	cmp r6, #0
	bne _081D0F94
	b _081D11A6
_081D0F94:
	mov r8, r6
	adds r4, r6, #0
	adds r4, #0x3c
	ldr r1, _081D1060 @ =0x0000BB68
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r1, r6, #0
	adds r1, #0xb0
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc6
	strb r2, [r0]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D0FD8
	bl Script_GetValue
	strh r0, [r6, #0x1c]
	bl Script_GetValue
	strh r0, [r6, #0x1e]
	bl Script_GetValue
	strh r0, [r6, #0x20]
_081D0FD8:
	ldr r0, [r6, #0x1c]
	ldr r1, [r6, #0x20]
	str r0, [r6, #0x58]
	str r1, [r6, #0x5c]
	movs r0, #0x52
	movs r1, #2
	bl VM_GetKeywordValue
	strb r0, [r6, #7]
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r6, #0
	adds r5, #0xbc
	strb r0, [r5]
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0xbe
	strh r0, [r1]
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0xb2
	strh r0, [r1]
	movs r0, #0x73
	movs r1, #1
	bl VM_GetKeywordValue
	adds r4, r6, #0
	adds r4, #0xb6
	strh r0, [r4]
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r6, #0
	adds r7, #0xba
	strh r0, [r7]
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0xc2
	strh r0, [r1]
	lsls r0, r0, #0x10
	mov sl, r4
	cmp r0, #0
	beq _081D104E
	adds r0, r6, #0
	movs r1, #4
	bl FUN_081d0e74
_081D104E:
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r0, #0
	beq _081D1064
	cmp r0, #1
	beq _081D1074
	b _081D107E
	.align 2, 0
_081D105C: .4byte 0x0300018C
_081D1060: .4byte 0x0000BB68
_081D1064:
	ldr r0, [r6, #0xc]
	ldr r1, _081D1070 @ =0x00000139
	bl Video_SetAuxSpritePltt
	b _081D107E
	.align 2, 0
_081D1070: .4byte 0x00000139
_081D1074:
	ldr r0, [r6, #0xc]
	movs r1, #0x9d
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
_081D107E:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D10A4
	adds r4, r6, #0
	adds r4, #0x2c
	mov r2, sb
	ldr r1, [r2, #0x18]
	ldrb r0, [r5]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	b _081D10BA
_081D10A4:
	adds r4, r6, #0
	adds r4, #0x2c
	mov r0, sb
	ldr r1, [r0, #0x18]
	ldrb r0, [r5]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
_081D10BA:
	mov r2, sl
	ldrh r1, [r2]
	adds r0, r6, #0
	adds r0, #0xc0
	strh r1, [r0]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, r8
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D10F4
	mov r2, r8
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D1100
_081D10F4:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
_081D1100:
	str r0, [r2]
	ldrb r0, [r4, #4]
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
	beq _081D1126
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D1130
_081D1126:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D1130:
	mov r2, r8
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D1168 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D11A0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D116C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D1162
	ldrb r0, [r4, #5]
_081D1162:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D117C
	.align 2, 0
_081D1168: .4byte 0x0000FFFF
_081D116C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D117C
	strh r1, [r4, #8]
_081D117C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D11A0
	movs r0, #1
	strb r0, [r4, #7]
_081D11A0:
	adds r0, r6, #0
	bl FUN_081d1924
_081D11A6:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d11b8
FUN_081d11b8: @ 0x081D11B8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _081D11E8 @ =0x0300018C
	ldr r5, [r0]
	movs r0, #0xa6
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	adds r0, #0xb0
	ldrh r0, [r0]
	cmp r0, #2
	bne _081D1200
	adds r2, r4, #0
	adds r2, #0x30
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081D11EC
	movs r0, #0xfb
	ands r0, r1
	b _081D11F0
	.align 2, 0
_081D11E8: .4byte 0x0300018C
_081D11EC:
	movs r0, #4
	orrs r0, r1
_081D11F0:
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x33
	ldrb r0, [r0]
	ldrh r1, [r4, #0x3a]
	subs r0, r0, r1
	strh r0, [r4, #0x3a]
	b _081D1258
_081D1200:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D122E
	adds r0, r4, #0
	adds r0, #0x2c
	ldr r1, [r5, #0x18]
	adds r2, r4, #0
	adds r2, #0xbc
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081d0e84
	b _081D1250
_081D122E:
	adds r0, r4, #0
	adds r0, #0x2c
	ldr r1, [r5, #0x18]
	adds r2, r4, #0
	adds r2, #0xbc
	ldrb r3, [r2]
	movs r2, #4
	orrs r2, r3
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081d0e84
_081D1250:
	adds r1, r4, #0
	adds r1, #0xb0
	movs r0, #2
	strh r0, [r1]
_081D1258:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d1260
FUN_081d1260: @ 0x081D1260
	push {r4, lr}
	adds r2, r0, #0
	mov ip, r2
	adds r3, r2, #0
	adds r3, #0xa4
	ldrh r0, [r3]
	cmp r0, #0
	beq _081D1282
	adds r4, r2, #0
	adds r4, #0x66
	ldrh r0, [r4]
	movs r1, #4
	orrs r1, r0
	strh r1, [r4]
	ldrh r0, [r3]
	subs r0, #1
	b _081D128C
_081D1282:
	adds r3, r2, #0
	adds r3, #0x66
	ldrh r1, [r3]
	ldr r0, _081D12AC @ =0x0000FFFB
	ands r0, r1
_081D128C:
	strh r0, [r3]
	mov r4, ip
	adds r4, #0xbd
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D12B0
	ldr r0, [r2, #0xc]
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _081D12DA
	.align 2, 0
_081D12AC: .4byte 0x0000FFFB
_081D12B0:
	mov r0, ip
	adds r0, #0xba
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _081D12C2
	cmp r0, #1
	beq _081D12D0
	b _081D12DA
_081D12C2:
	ldr r0, [r2, #0xc]
	ldr r1, _081D12CC @ =0x00000139
	bl Video_SetAuxSpritePltt
	b _081D12DA
	.align 2, 0
_081D12CC: .4byte 0x00000139
_081D12D0:
	ldr r0, [r2, #0xc]
	movs r1, #0x9d
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
_081D12DA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d12e0
FUN_081d12e0: @ 0x081D12E0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r7, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	bl FUN_081d1260
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D131E
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D1326
_081D131E:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D1326:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D134A
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D1352
_081D134A:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D1352:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D138C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D13D2
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D1396
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D1390
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D13AC
	.align 2, 0
_081D138C: .4byte 0x0000FFFF
_081D1390:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D13AA
_081D1396:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D13AA
	strh r1, [r4, #8]
	movs r2, #1
	b _081D13AC
_081D13AA:
	movs r2, #0
_081D13AC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D13D4
	movs r0, #1
	strb r0, [r4, #7]
	b _081D13D4
_081D13D2:
	movs r2, #0
_081D13D4:
	cmp r2, #0
	beq _081D145E
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081D1406
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r7, #0x18]
	adds r2, r5, #0
	adds r2, #0xbc
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	adds r0, r5, #0
	movs r1, #1
	bl FUN_081d0e74
	b _081D1424
_081D1406:
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r7, #0x18]
	adds r2, r5, #0
	adds r2, #0xbc
	ldrb r2, [r2]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r0, r5, #0
	movs r1, #2
	bl FUN_081d0e74
_081D1424:
	adds r1, r5, #0
	adds r1, #0xb0
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xc6
	strb r2, [r0]
	subs r0, #8
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r0, #0xb6
	ldrh r0, [r0]
	str r0, [sp, #8]
	add r1, sp, #0xc
	add r0, sp, #4
	str r0, [r1, #4]
	ldr r2, _081D1468 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r2, #2
	orrs r0, r2
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r0, #0xb2
	ldrh r0, [r0]
	bl Script_ExecById
_081D145E:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D1468: .4byte 0xFFFF0000

	thumb_func_start FUN_081d146c
FUN_081d146c: @ 0x081D146C
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d1470
FUN_081d1470: @ 0x081D1470
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #4
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D14DA
	adds r0, r4, #0
	adds r0, #0xc0
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081D1494
	adds r0, r4, #0
	movs r1, #1
	b _081D1498
_081D1494:
	adds r0, r4, #0
	movs r1, #2
_081D1498:
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D14DA
	adds r2, r4, #0
	adds r2, #0x66
	ldrh r0, [r2]
	movs r1, #4
	orrs r1, r0
	strh r1, [r2]
	adds r0, r4, #0
	movs r1, #8
	bl FUN_081d0e94
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D14DA
	adds r0, r4, #0
	adds r0, #0xc2
	adds r1, r4, #0
	adds r1, #0xc4
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhi _081D14DA
	adds r1, r4, #0
	adds r1, #0xa4
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_081d11b8
_081D14DA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d14e0
FUN_081d14e0: @ 0x081D14E0
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r3, r5, #0
	adds r3, #0xc6
	ldrb r0, [r3]
	cmp r0, #0
	beq _081D1502
	adds r1, #0xc4
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	strb r2, [r3]
_081D1502:
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D1532
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D153A
_081D1532:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D153A:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D155E
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D1566
_081D155E:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D1566:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D159C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D15D4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D15A0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D1596
	ldrb r0, [r4, #5]
_081D1596:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D15B0
	.align 2, 0
_081D159C: .4byte 0x0000FFFF
_081D15A0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D15B0
	strh r1, [r4, #8]
_081D15B0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D15D4
	movs r0, #1
	strb r0, [r4, #7]
_081D15D4:
	adds r0, r5, #0
	bl FUN_081d1260
	adds r0, r5, #0
	bl FUN_081d1470
	adds r0, r5, #0
	bl FUN_081d1744
	adds r1, r5, #0
	adds r1, #0xc4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d15f8
FUN_081d15f8: @ 0x081D15F8
	bx lr
	.align 2, 0

	thumb_func_start Entity081d16ec_Update
Entity081d16ec_Update: @ 0x081D15FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x1c
	ldr r1, _081D162C @ =0x0000097C
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081D165A
	movs r4, #0
	ldr r0, _081D162C @ =0x0000097C
	adds r6, r5, r0
	ldr r1, _081D1630 @ =0x085AE0B8
	mov r8, r1
_081D161C:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D1634
	movs r0, #1
	b _081D1636
	.align 2, 0
_081D162C: .4byte 0x0000097C
_081D1630: .4byte 0x085AE0B8
_081D1634:
	movs r0, #0
_081D1636:
	cmp r0, #0
	beq _081D1654
	movs r0, #0xc8
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r7
	adds r0, r1, #0
	adds r0, #0xb0
	ldrh r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081D1654:
	adds r4, #1
	cmp r4, #0xb
	ble _081D161C
_081D165A:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081d16ec_Destroy
Entity081d16ec_Destroy: @ 0x081D1668
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r0, _081D1684 @ =0x0000097C
	adds r7, r6, r0
_081D1672:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D1688
	movs r0, #1
	b _081D168A
	.align 2, 0
_081D1684: .4byte 0x0000097C
_081D1688:
	movs r0, #0
_081D168A:
	cmp r0, #0
	beq _081D16A6
	movs r0, #0xc8
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x1c
	adds r4, r6, r4
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x60
	adds r0, r4, #0
	bl FUN_08236424
_081D16A6:
	adds r5, #1
	cmp r5, #0xb
	ble _081D1672
	ldr r1, _081D16B8 @ =0x0300018C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D16B8: .4byte 0x0300018C

	thumb_func_start Entity081d16ec_Init
Entity081d16ec_Init: @ 0x081D16BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081D16DC @ =0x0000922E
	ldr r1, _081D16E0 @ =0x0000B952
	bl GetFile
	str r0, [r4, #0x18]
	ldr r0, _081D16E4 @ =0x0300018C
	str r4, [r0]
	ldr r0, _081D16E8 @ =0x0000097C
	adds r4, r4, r0
	movs r0, #0
	str r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081D16DC: .4byte 0x0000922E
_081D16E0: .4byte 0x0000B952
_081D16E4: .4byte 0x0300018C
_081D16E8: .4byte 0x0000097C

	thumb_func_start Entity081d16ec_Create
Entity081d16ec_Create: @ 0x081D16EC
	push {r4, lr}
	ldr r0, _081D1724 @ =0x0300018C
	ldr r0, [r0]
	cmp r0, #0
	bne _081D1732
	movs r1, #0x98
	lsls r1, r1, #4
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D1730
	ldr r1, _081D1728 @ =Entity081d16ec_Update
	ldr r2, _081D172C @ =Entity081d16ec_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081d16ec_Init
	cmp r0, #0
	bge _081D1730
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D1732
	.align 2, 0
_081D1724: .4byte 0x0300018C
_081D1728: .4byte Entity081d16ec_Update
_081D172C: .4byte Entity081d16ec_Destroy
_081D1730:
	adds r0, r4, #0
_081D1732:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d1738
FUN_081d1738: @ 0x081D1738
	ldr r1, _081D1740 @ =0x0300018C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D1740: .4byte 0x0300018C
