	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a1010
FUN_080a1010: @ 0x080A1010
	push {r4, lr}
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1024
	bl VM_GetValue
	adds r1, r0, #0
	b _080A1028
_080A1024:
	movs r1, #0xe1
	lsls r1, r1, #3
_080A1028:
	ldr r4, _080A1054 @ =0x03002C40
	ldr r0, [r4]
	strh r1, [r0, #0x18]
	lsls r0, r1, #0x10
	cmp r0, #0
	beq _080A104E
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	bne _080A1046
	movs r0, #0x49
	movs r1, #0
	bl TryAddItem
_080A1046:
	ldr r0, [r4]
	adds r0, #0x18
	bl FUN_0809c544
_080A104E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A1054: .4byte 0x03002C40

	thumb_func_start FUN_080a1058
FUN_080a1058: @ 0x080A1058
	push {lr}
	ldr r0, _080A1068 @ =0x03002C40
	ldr r0, [r0]
	cmp r0, #0
	beq _080A106C
	ldrh r0, [r0, #0x18]
	b _080A106E
	.align 2, 0
_080A1068: .4byte 0x03002C40
_080A106C:
	movs r0, #0
_080A106E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a1074
FUN_080a1074: @ 0x080A1074
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	bne _080A109C
	movs r2, #0x80
	lsls r2, r2, #5
	ldr r0, _080A1094 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A1098 @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	orrs r2, r1
	strh r2, [r0]
	b _080A10D8
	.align 2, 0
_080A1094: .4byte 0x030046A0
_080A1098: .4byte 0x00000934
_080A109C:
	ldr r0, _080A10E0 @ =0x030046A0
	ldr r1, [r0]
	ldr r0, _080A10E4 @ =0x00000934
	adds r1, r1, r0
	ldr r0, _080A10E8 @ =0xFFFFEFFF
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	ldrh r0, [r4, #0x18]
	subs r0, #1
	strh r0, [r4, #0x18]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080A10D8
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	beq _080A10C8
	movs r0, #0x49
	bl RemoveSpecifiedItem
_080A10C8:
	bl FUN_0809c58c
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _080A10D8
	movs r1, #0
	bl VM_ExecByID
_080A10D8:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A10E0: .4byte 0x030046A0
_080A10E4: .4byte 0x00000934
_080A10E8: .4byte 0xFFFFEFFF

	thumb_func_start FUN_080a10ec
FUN_080a10ec: @ 0x080A10EC
	push {lr}
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	beq _080A10FE
	movs r0, #0x49
	bl RemoveSpecifiedItem
_080A10FE:
	ldr r1, _080A1108 @ =0x03002C40
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_080A1108: .4byte 0x03002C40

	thumb_func_start FUN_080a110c
FUN_080a110c: @ 0x080A110C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1120
	bl VM_GetValue
	b _080A1124
_080A1120:
	movs r0, #0xe1
	lsls r0, r0, #3
_080A1124:
	strh r0, [r4, #0x18]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1134
	bl VM_GetValue
_080A1134:
	str r0, [r4, #0x1c]
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	beq _080A1156
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	bne _080A114E
	movs r0, #0x49
	movs r1, #0
	bl TryAddItem
_080A114E:
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0809c544
_080A1156:
	ldr r0, _080A1164 @ =0x03002C40
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A1164: .4byte 0x03002C40

	thumb_func_start FUN_080a1168
FUN_080a1168: @ 0x080A1168
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080A11A4 @ =0x03002C40
	ldr r0, [r0]
	cmp r0, #0
	bne _080A11B2
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A11B0
	ldr r1, _080A11A8 @ =FUN_080a1074
	ldr r2, _080A11AC @ =FUN_080a10ec
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a110c
	cmp r0, #0
	bge _080A11B0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A11B2
	.align 2, 0
_080A11A4: .4byte 0x03002C40
_080A11A8: .4byte FUN_080a1074
_080A11AC: .4byte FUN_080a10ec
_080A11B0:
	adds r0, r4, #0
_080A11B2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a11b8
FUN_080a11b8: @ 0x080A11B8
	push {lr}
	ldr r0, _080A11D0 @ =0x03000148
	ldr r1, [r0]
	cmp r1, #0
	beq _080A11CC
	movs r0, #0
	strh r0, [r1, #0x1a]
	strh r0, [r1, #0x2a]
	strh r0, [r1, #0x26]
	strh r0, [r1, #0x2c]
_080A11CC:
	pop {r0}
	bx r0
	.align 2, 0
_080A11D0: .4byte 0x03000148

	thumb_func_start FUN_080a11d4
FUN_080a11d4: @ 0x080A11D4
	push {r4, lr}
	ldr r4, _080A11FC @ =0x03000148
	ldr r1, [r4]
	cmp r1, #0
	beq _080A123A
	movs r0, #1
	strh r0, [r1, #0x1a]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1200
	bl VM_GetValue
	ldr r1, [r4]
	strh r0, [r1, #0x1c]
	bl VM_GetValue
	ldr r1, [r4]
	b _080A1206
	.align 2, 0
_080A11FC: .4byte 0x03000148
_080A1200:
	ldr r1, [r4]
	movs r0, #3
	strh r0, [r1, #0x1c]
_080A1206:
	strh r0, [r1, #0x1e]
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1228
	bl VM_GetValue
	ldr r4, _080A1224 @ =0x03000148
	ldr r1, [r4]
	strh r0, [r1, #0x20]
	bl VM_GetValue
	ldr r1, [r4]
	b _080A1230
	.align 2, 0
_080A1224: .4byte 0x03000148
_080A1228:
	ldr r0, _080A1240 @ =0x03000148
	ldr r1, [r0]
	movs r0, #0x78
	strh r0, [r1, #0x20]
_080A1230:
	strh r0, [r1, #0x22]
	ldr r0, _080A1240 @ =0x03000148
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #0x2c]
_080A123A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A1240: .4byte 0x03000148

	thumb_func_start FUN_080a1244
FUN_080a1244: @ 0x080A1244
	push {r4, lr}
	ldr r4, _080A1268 @ =0x03000148
	ldr r1, [r4]
	cmp r1, #0
	beq _080A12CE
	movs r0, #2
	strh r0, [r1, #0x1a]
	movs r0, #0x64
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A126C
	bl VM_GetValue
	ldr r1, [r4]
	strh r0, [r1, #0x2a]
	b _080A1270
	.align 2, 0
_080A1268: .4byte 0x03000148
_080A126C:
	ldr r0, [r4]
	strh r1, [r0, #0x2a]
_080A1270:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1290
	bl VM_GetValue
	ldr r4, _080A128C @ =0x03000148
	ldr r1, [r4]
	strh r0, [r1, #0x1c]
	bl VM_GetValue
	ldr r1, [r4]
	b _080A1298
	.align 2, 0
_080A128C: .4byte 0x03000148
_080A1290:
	ldr r0, _080A12B8 @ =0x03000148
	ldr r1, [r0]
	movs r0, #3
	strh r0, [r1, #0x1c]
_080A1298:
	strh r0, [r1, #0x1e]
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A12BC
	bl VM_GetValue
	ldr r4, _080A12B8 @ =0x03000148
	ldr r1, [r4]
	strh r0, [r1, #0x20]
	bl VM_GetValue
	ldr r1, [r4]
	b _080A12C4
	.align 2, 0
_080A12B8: .4byte 0x03000148
_080A12BC:
	ldr r0, _080A12D4 @ =0x03000148
	ldr r1, [r0]
	movs r0, #0x78
	strh r0, [r1, #0x20]
_080A12C4:
	strh r0, [r1, #0x22]
	ldr r0, _080A12D4 @ =0x03000148
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #0x2c]
_080A12CE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A12D4: .4byte 0x03000148

	thumb_func_start FUN_080a12d8
FUN_080a12d8: @ 0x080A12D8
	push {r4, lr}
	ldr r0, _080A12FC @ =0x03000148
	ldr r0, [r0]
	cmp r0, #0
	beq _080A12F4
	movs r0, #0x48
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A12F4
	ldr r4, _080A1300 @ =0x03002B84
	bl VM_GetValue
	strh r0, [r4]
_080A12F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A12FC: .4byte 0x03000148
_080A1300: .4byte 0x03002B84

	thumb_func_start FUN_080a1304
FUN_080a1304: @ 0x080A1304
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x24]
	lsls r0, r1, #4
	subs r0, r0, r1
	ldrh r1, [r4, #0x26]
	adds r0, r0, r1
	asrs r0, r0, #4
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x2a]
	lsls r0, r0, #4
	ldrh r2, [r4, #0x28]
	ldr r3, _080A133C @ =0xFFFFF000
	adds r1, r2, r3
	subs r1, r0, r1
	ldr r3, _080A1340 @ =0x00000FFF
	ands r1, r3
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080A1344
	movs r0, #0x80
	lsls r0, r0, #5
	subs r1, r0, r1
	adds r0, r2, r0
	asrs r1, r1, #4
	subs r0, r0, r1
	b _080A1348
	.align 2, 0
_080A133C: .4byte 0xFFFFF000
_080A1340: .4byte 0x00000FFF
_080A1344:
	asrs r0, r1, #4
	adds r0, r2, r0
_080A1348:
	ands r0, r3
	strh r0, [r4, #0x28]
	ldr r1, _080A1370 @ =0x03002BAC
	ldrh r0, [r4, #0x24]
	lsrs r0, r0, #4
	strh r0, [r1]
	ldr r1, _080A1374 @ =0x03002B90
	ldrh r0, [r4, #0x28]
	lsrs r0, r0, #4
	strh r0, [r1]
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	beq _080A1378
	cmp r0, #1
	bgt _080A1368
	b _080A1470
_080A1368:
	cmp r0, #2
	beq _080A13F0
	b _080A1470
	.align 2, 0
_080A1370: .4byte 0x03002BAC
_080A1374: .4byte 0x03002B90
_080A1378:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0
	bne _080A146C
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne _080A138C
	ldrh r0, [r4, #0x1c]
	lsls r0, r0, #4
	strh r0, [r4, #0x26]
	b _080A13AE
_080A138C:
	ldr r2, _080A13D0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A13D4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _080A13D8 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	ldrh r1, [r4, #0x1e]
	bl Mod
	ldrh r1, [r4, #0x1c]
	adds r1, r1, r0
	lsls r1, r1, #4
	strh r1, [r4, #0x26]
_080A13AE:
	ldr r2, _080A13D0 @ =0x030046B8
	ldr r0, [r2]
	adds r1, r0, #1
	ldr r3, _080A13D4 @ =0x000003FF
	ands r1, r3
	str r1, [r2]
	lsls r0, r1, #1
	ldr r5, _080A13D8 @ =0x0203B400
	adds r0, r0, r5
	ldrb r0, [r0]
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	bne _080A13DC
	ldrh r0, [r4, #0x20]
	b _080A146E
	.align 2, 0
_080A13D0: .4byte 0x030046B8
_080A13D4: .4byte 0x000003FF
_080A13D8: .4byte 0x0203B400
_080A13DC:
	adds r0, r1, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080A13EC @ =0x0203B400
	adds r0, r0, r1
	b _080A144E
	.align 2, 0
_080A13EC: .4byte 0x0203B400
_080A13F0:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0
	bne _080A146C
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne _080A1404
	ldrh r0, [r4, #0x1c]
	lsls r0, r0, #4
	strh r0, [r4, #0x26]
	b _080A1426
_080A1404:
	ldr r2, _080A1430 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A1434 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080A1438 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r4, #0x1e]
	bl Mod
	ldrh r1, [r4, #0x1c]
	adds r1, r1, r0
	lsls r1, r1, #4
	strh r1, [r4, #0x26]
_080A1426:
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	bne _080A143C
	ldrh r0, [r4, #0x20]
	b _080A146E
	.align 2, 0
_080A1430: .4byte 0x030046B8
_080A1434: .4byte 0x000003FF
_080A1438: .4byte 0x0203B400
_080A143C:
	ldr r2, _080A1460 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A1464 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _080A1468 @ =0x0203B400
	adds r0, r0, r5
_080A144E:
	ldrh r0, [r0]
	ldrh r1, [r4, #0x22]
	bl Mod
	ldrh r1, [r4, #0x20]
	adds r1, r1, r0
	strh r1, [r4, #0x2c]
	b _080A1470
	.align 2, 0
_080A1460: .4byte 0x030046B8
_080A1464: .4byte 0x000003FF
_080A1468: .4byte 0x0203B400
_080A146C:
	subs r0, #1
_080A146E:
	strh r0, [r4, #0x2c]
_080A1470:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a1478
FUN_080a1478: @ 0x080A1478
	ldr r0, _080A1490 @ =0x03002B84
	movs r1, #0
	strh r1, [r0]
	ldr r0, _080A1494 @ =0x03002BAC
	strh r1, [r0]
	ldr r0, _080A1498 @ =0x03002B90
	strh r1, [r0]
	ldr r1, _080A149C @ =0x03000148
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080A1490: .4byte 0x03002B84
_080A1494: .4byte 0x03002BAC
_080A1498: .4byte 0x03002B90
_080A149C: .4byte 0x03000148

	thumb_func_start FUN_080a14a0
FUN_080a14a0: @ 0x080A14A0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	strh r1, [r5, #0x18]
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A14B6
	bl VM_GetValue
	b _080A14B8
_080A14B6:
	movs r0, #1
_080A14B8:
	strh r0, [r5, #0x1a]
	movs r0, #0x48
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A14D8
	ldr r4, _080A14D4 @ =0x03002B84
	bl VM_GetValue
	adds r1, r0, #0
	strh r1, [r4]
	b _080A14DC
	.align 2, 0
_080A14D4: .4byte 0x03002B84
_080A14D8:
	ldr r1, _080A14EC @ =0x03002B84
	strh r2, [r1]
_080A14DC:
	ldrh r1, [r5, #0x1a]
	cmp r1, #1
	beq _080A14FC
	cmp r1, #1
	bgt _080A14F0
	cmp r1, #0
	beq _080A14F6
	b _080A164A
	.align 2, 0
_080A14EC: .4byte 0x03002B84
_080A14F0:
	cmp r1, #2
	beq _080A1598
	b _080A164A
_080A14F6:
	strh r1, [r5, #0x2a]
	strh r1, [r5, #0x26]
	b _080A164A
_080A14FC:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1512
	bl VM_GetValue
	strh r0, [r5, #0x1c]
	bl VM_GetValue
	b _080A1516
_080A1512:
	movs r0, #3
	strh r0, [r5, #0x1c]
_080A1516:
	strh r0, [r5, #0x1e]
	movs r0, #0x74
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A1532
	bl VM_GetValue
	strh r0, [r5, #0x20]
	bl VM_GetValue
	adds r1, r0, #0
	b _080A1536
_080A1532:
	movs r1, #0x78
	strh r1, [r5, #0x20]
_080A1536:
	strh r1, [r5, #0x22]
	ldr r3, _080A1558 @ =0x030046B8
	ldr r1, [r3]
	adds r2, r1, #1
	ldr r4, _080A155C @ =0x000003FF
	ands r2, r4
	str r2, [r3]
	lsls r1, r2, #1
	ldr r6, _080A1560 @ =0x0203B400
	adds r1, r1, r6
	ldrb r1, [r1]
	strh r1, [r5, #0x2a]
	ldrh r1, [r5, #0x1e]
	cmp r1, #0
	bne _080A1564
	ldrh r1, [r5, #0x1c]
	b _080A157E
	.align 2, 0
_080A1558: .4byte 0x030046B8
_080A155C: .4byte 0x000003FF
_080A1560: .4byte 0x0203B400
_080A1564:
	adds r0, r2, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _080A1594 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r5, #0x1e]
	bl Mod
	adds r2, r0, #0
	ldrh r1, [r5, #0x1c]
	adds r1, r1, r2
_080A157E:
	lsls r1, r1, #4
	strh r1, [r5, #0x26]
	ldrh r1, [r5, #0x1c]
	lsls r1, r1, #4
	strh r1, [r5, #0x24]
	ldrh r1, [r5, #0x22]
	cmp r1, #0
	bne _080A1628
	ldrh r1, [r5, #0x20]
	b _080A1648
	.align 2, 0
_080A1594: .4byte 0x0203B400
_080A1598:
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A15A6
	bl VM_GetValue
_080A15A6:
	strh r0, [r5, #0x2a]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A15BE
	bl VM_GetValue
	strh r0, [r5, #0x1c]
	bl VM_GetValue
	b _080A15C2
_080A15BE:
	movs r0, #3
	strh r0, [r5, #0x1c]
_080A15C2:
	strh r0, [r5, #0x1e]
	movs r0, #0x74
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A15DE
	bl VM_GetValue
	strh r0, [r5, #0x20]
	bl VM_GetValue
	adds r1, r0, #0
	b _080A15E2
_080A15DE:
	movs r1, #0x78
	strh r1, [r5, #0x20]
_080A15E2:
	strh r1, [r5, #0x22]
	ldrh r1, [r5, #0x1e]
	cmp r1, #0
	bne _080A15EE
	ldrh r1, [r5, #0x1c]
	b _080A160E
_080A15EE:
	ldr r2, _080A161C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A1620 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080A1624 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r5, #0x1e]
	bl Mod
	adds r2, r0, #0
	ldrh r1, [r5, #0x1c]
	adds r1, r1, r2
_080A160E:
	lsls r1, r1, #4
	strh r1, [r5, #0x26]
	ldrh r1, [r5, #0x22]
	cmp r1, #0
	bne _080A1628
	ldrh r1, [r5, #0x20]
	b _080A1648
	.align 2, 0
_080A161C: .4byte 0x030046B8
_080A1620: .4byte 0x000003FF
_080A1624: .4byte 0x0203B400
_080A1628:
	ldr r2, _080A1654 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A1658 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r6, _080A165C @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	ldrh r1, [r5, #0x22]
	bl Mod
	adds r2, r0, #0
	ldrh r1, [r5, #0x20]
	adds r1, r1, r2
_080A1648:
	strh r1, [r5, #0x2c]
_080A164A:
	ldr r1, _080A1660 @ =0x03000148
	str r5, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A1654: .4byte 0x030046B8
_080A1658: .4byte 0x000003FF
_080A165C: .4byte 0x0203B400
_080A1660: .4byte 0x03000148

	thumb_func_start FUN_080a1664
FUN_080a1664: @ 0x080A1664
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080A169C @ =0x03000148
	ldr r0, [r0]
	cmp r0, #0
	bne _080A16AA
	movs r0, #9
	movs r1, #0x30
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A16A8
	ldr r1, _080A16A0 @ =FUN_080a1304
	ldr r2, _080A16A4 @ =FUN_080a1478
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a14a0
	cmp r0, #0
	bge _080A16A8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A16AA
	.align 2, 0
_080A169C: .4byte 0x03000148
_080A16A0: .4byte FUN_080a1304
_080A16A4: .4byte FUN_080a1478
_080A16A8:
	adds r0, r4, #0
_080A16AA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a16b0
FUN_080a16b0: @ 0x080A16B0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A16FC @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A1700 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _080A170C
	ldr r0, _080A1704 @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	movs r3, #0x28
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	cmp r3, #0x7f
	bgt _080A170C
	cmp r1, #0x7f
	bgt _080A170C
	adds r0, r3, #0
	muls r0, r3, r0
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	ldr r1, _080A1708 @ =0x00003FFF
	cmp r0, r1
	bgt _080A170C
	movs r0, #1
	b _080A170E
	.align 2, 0
_080A16FC: .4byte 0x030046A0
_080A1700: .4byte 0x00000942
_080A1704: .4byte 0x03002BE0
_080A1708: .4byte 0x00003FFF
_080A170C:
	movs r0, #0
_080A170E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a1714
FUN_080a1714: @ 0x080A1714
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080A1740 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A1744 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r5, [r0, r2]
	cmp r5, #0
	bne _080A174C
	ldrh r0, [r4, #0x1e]
	cmp r0, #1
	bne _080A1738
	ldr r0, _080A1748 @ =0x00000237
	bl sound_08240740
	strh r5, [r4, #0x1e]
_080A1738:
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x46
	b _080A17FC
	.align 2, 0
_080A1740: .4byte 0x030046A0
_080A1744: .4byte 0x00000942
_080A1748: .4byte 0x00000237
_080A174C:
	adds r0, r4, #0
	bl FUN_080a16b0
	adds r5, r0, #0
	cmp r5, #0
	beq _080A17E8
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne _080A1778
	ldr r0, _080A17A4 @ =0x00000237
	bl PlaySound_082406e0
	movs r0, #1
	strh r0, [r4, #0x1e]
	adds r0, r4, #0
	adds r0, #0xf4
	ldr r0, [r0]
	cmp r0, #0
	beq _080A1778
	movs r1, #0
	bl VM_ExecByID
_080A1778:
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x45
	bl Video_SetAuxSpritePltt
	adds r3, r4, #0
	adds r3, #0xac
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrh r0, [r4, #0x1a]
	lsrs r0, r0, #1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A17A8
	movs r0, #4
	orrs r2, r0
	b _080A17AE
	.align 2, 0
_080A17A4: .4byte 0x00000237
_080A17A8:
	movs r0, #5
	rsbs r0, r0, #0
	ands r2, r0
_080A17AE:
	str r2, [r3]
	ldrh r1, [r4, #0x1a]
	movs r0, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _080A17DC
	adds r0, r4, #0
	adds r0, #0x80
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	adds r1, #0x84
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0x80
	lsls r2, r2, #3
	movs r3, #0x80
	str r3, [sp]
	ldr r3, _080A17E4 @ =0x0000B546
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
_080A17DC:
	ldrh r0, [r4, #0x1a]
	adds r0, #1
	strh r0, [r4, #0x1a]
	b _080A180E
	.align 2, 0
_080A17E4: .4byte 0x0000B546
_080A17E8:
	ldrh r0, [r4, #0x1e]
	cmp r0, #1
	bne _080A17F6
	ldr r0, _080A1818 @ =0x00000237
	bl sound_08240740
	strh r5, [r4, #0x1e]
_080A17F6:
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x44
_080A17FC:
	bl Video_SetAuxSpritePltt
	adds r2, r4, #0
	adds r2, #0xac
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	strh r5, [r4, #0x1a]
_080A180E:
	movs r0, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A1818: .4byte 0x00000237

	thumb_func_start FUN_080a181c
FUN_080a181c: @ 0x080A181C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x1c]
	cmp r0, #0
	beq _080A182E
	adds r0, r4, #0
	adds r0, #0x20
	bl Mover_Unlink
_080A182E:
	adds r0, r4, #0
	adds r0, #0x64
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0xac
	bl AuxSprite_Remove
	ldr r0, _080A184C @ =0x00000237
	bl sound_08240740
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A184C: .4byte 0x00000237

	thumb_func_start FUN_080a1850
FUN_080a1850: @ 0x080A1850
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	strh r1, [r6, #0x18]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1874
	bl VM_GetValue
	strh r0, [r6, #0x28]
	bl VM_GetValue
	strh r0, [r6, #0x2a]
	bl VM_GetValue
	b _080A1878
_080A1874:
	strh r0, [r6, #0x28]
	strh r0, [r6, #0x2a]
_080A1878:
	strh r0, [r6, #0x2c]
	adds r5, r6, #0
	adds r5, #0x64
	adds r4, r6, #0
	adds r4, #0x90
	ldr r1, _080A1900 @ =0x0000A680
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0xa
	strh r0, [r5, #0x10]
	movs r0, #3
	strb r0, [r5, #7]
	adds r0, r4, #0
	movs r1, #0x46
	bl Video_SetAuxSpritePltt
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A18BE
	bl VM_GetValue
	cmp r0, #0
	beq _080A18BE
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	str r0, [r6, #0x64]
_080A18BE:
	movs r0, #0
	strh r0, [r6, #0x1e]
	ldr r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r0, #0x68
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1904
	bl VM_GetValue
	strh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A1906
	adds r4, r6, #0
	adds r4, #0x20
	ldrh r1, [r6, #0x18]
	adds r2, r5, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Mover_Init
	adds r0, r4, #0
	bl FUN_08002a48
	b _080A1906
	.align 2, 0
_080A1900: .4byte 0x0000A680
_080A1904:
	strh r0, [r6, #0x1c]
_080A1906:
	adds r5, r6, #0
	adds r5, #0xac
	adds r4, r6, #0
	adds r4, #0xd8
	ldr r1, _080A196C @ =0x0000A680
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0xb
	strh r0, [r5, #0x10]
	movs r0, #1
	strb r0, [r5, #7]
	adds r0, r4, #0
	movs r1, #0x45
	bl Video_SetAuxSpritePltt
	ldr r0, [r5]
	ldr r1, _080A1970 @ =0x00000201
	orrs r0, r1
	str r0, [r5]
	ldr r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldrh r0, [r5, #0x1c]
	subs r0, #0x80
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	subs r0, #0x80
	strh r0, [r5, #0x20]
	movs r0, #0x52
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A195E
	bl VM_GetValue
	adds r2, r0, #0
_080A195E:
	adds r1, r6, #0
	adds r1, #0xf4
	str r2, [r1]
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A196C: .4byte 0x0000A680
_080A1970: .4byte 0x00000201

	thumb_func_start FUN_080a1974
FUN_080a1974: @ 0x080A1974
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0xf8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A19AC
	ldr r1, _080A19A4 @ =FUN_080a1714
	ldr r2, _080A19A8 @ =FUN_080a181c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a1850
	cmp r0, #0
	bge _080A19AC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A19AE
	.align 2, 0
_080A19A4: .4byte FUN_080a1714
_080A19A8: .4byte FUN_080a181c
_080A19AC:
	adds r0, r4, #0
_080A19AE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a19b4
FUN_080a19b4: @ 0x080A19B4
	push {lr}
	movs r1, #0x40
	ldr r0, [r0, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _080A19C8
	adds r1, r2, #0
	adds r1, #0xc4
	movs r0, #1
	strb r0, [r1]
_080A19C8:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a19cc
FUN_080a19cc: @ 0x080A19CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	str r0, [sp, #0x30]
	mov r0, sp
	movs r3, #0
	movs r2, #2
	strh r2, [r0]
	strh r3, [r0, #2]
	mov r1, sp
	movs r0, #0x40
	strh r0, [r1, #6]
	movs r0, #3
	strh r0, [r1, #8]
	movs r0, #6
	strh r0, [r1, #0xa]
	mov r0, sp
	strh r2, [r0, #0xc]
	strh r2, [r0, #0xe]
	movs r0, #0x3c
	strh r0, [r1, #0x10]
	movs r0, #8
	strh r0, [r1, #0x12]
	mov r0, sp
	strh r3, [r0, #0x14]
	movs r1, #0xff
	strh r1, [r0, #0x16]
	strh r1, [r0, #0x18]
	strh r3, [r0, #0x1a]
	strh r1, [r0, #0x1c]
	strh r3, [r0, #0x1e]
	strh r1, [r0, #0x20]
	strh r3, [r0, #0x22]
	strh r1, [r0, #0x24]
	strh r3, [r0, #0x26]
	add r6, sp, #0x28
	ldr r0, _080A1AD4 @ =0x0203B400
	mov sl, r0
	ldr r4, _080A1AD8 @ =0x030046B8
	ldr r1, _080A1ADC @ =0x000003FF
	mov sb, r1
	movs r2, #0x96
	lsls r2, r2, #1
	mov r8, r2
	movs r7, #5
	adds r5, r6, #0
_080A1A2E:
	ldr r2, [sp, #0x30]
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	ldr r0, [r4]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	bl Mod
	ldrh r1, [r6]
	subs r1, #0x96
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x28]
	ldr r2, _080A1AE0 @ =0xFFFF0000
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x28]
	ldr r0, [r4]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	bl Mod
	ldr r2, [sp, #0x28]
	asrs r1, r2, #0x10
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _080A1AE4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x28]
	ldr r0, [r4]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	bl Mod
	ldrh r1, [r5, #4]
	subs r1, #0x96
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ldr r2, _080A1AE0 @ =0xFFFF0000
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #1
	adds r1, r5, #0
	mov r2, sp
	bl FUN_080155e4
	subs r7, #1
	cmp r7, #0
	bge _080A1A2E
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A1AD4: .4byte 0x0203B400
_080A1AD8: .4byte 0x030046B8
_080A1ADC: .4byte 0x000003FF
_080A1AE0: .4byte 0xFFFF0000
_080A1AE4: .4byte 0x0000FFFF

	thumb_func_start FUN_080a1ae8
FUN_080a1ae8: @ 0x080A1AE8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A1B1E
	ldr r0, [r4, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x18]
	adds r0, r4, #0
	bl FUN_080a19cc
	adds r1, r4, #0
	adds r1, #0xc8
	ldr r2, [r1]
	cmp r2, #0
	beq _080A1B18
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl VM_ExecByID
_080A1B18:
	adds r0, r4, #0
	bl KillEntity
_080A1B1E:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a1b28
FUN_080a1b28: @ 0x080A1B28
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0x60
	bl Hitbox_Unregister
	adds r0, r4, #0
	adds r0, #0xb0
	bl Map_RemoveTileOverride
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a1b48
FUN_080a1b48: @ 0x080A1B48
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	adds r5, r0, #0
	adds r5, #0x18
	adds r4, r0, #0
	adds r4, #0x44
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1B6C
	bl VM_GetValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl Video_GetAuxSprite
	b _080A1B74
_080A1B6C:
	ldr r1, _080A1BB8 @ =0x00009D41
	adds r0, r4, #0
	bl Video_GetAuxSprite
_080A1B74:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1B8C
	bl VM_GetValue
_080A1B8C:
	strh r0, [r5, #0x10]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1BB0
	bl VM_GetValue
	cmp r0, #0
	beq _080A1BB0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080A1BB0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A1BB8: .4byte 0x00009D41

	thumb_func_start FUN_080a1bbc
FUN_080a1bbc: @ 0x080A1BBC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x1c
	adds r6, r0, #0
	mov r8, r2
	adds r5, r6, #0
	adds r5, #0x60
	ldr r4, _080A1C34 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r4
	movs r3, #0x80
	orrs r0, r3
	ldr r2, _080A1C38 @ =0x0000FFFF
	ands r0, r2
	movs r2, #0x80
	lsls r2, r2, #0x10
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r3
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r4
	str r0, [r3, #4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080A1C3C @ =0x00004001
	movs r0, #0x20
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _080A1C40 @ =FUN_080a19b4
	adds r0, r5, #0
	adds r2, r6, #0
	bl Hitbox_SetHandler
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A1C34: .4byte 0xFFFF0000
_080A1C38: .4byte 0x0000FFFF
_080A1C3C: .4byte 0x00004001
_080A1C40: .4byte FUN_080a19b4

	thumb_func_start FUN_080a1c44
FUN_080a1c44: @ 0x080A1C44
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r7, r1, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1CA0
	bl VM_GetValue
	asrs r0, r0, #8
	lsls r0, r0, #8
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080A1C98 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080A1C9C @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl VM_GetValue
	asrs r0, r0, #8
	lsls r0, r0, #8
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _080A1CAA
	.align 2, 0
_080A1C98: .4byte 0xFFFF0000
_080A1C9C: .4byte 0x0000FFFF
_080A1CA0:
	ldr r1, _080A1CD8 @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_080A1CAA:
	add r6, sp, #8
	adds r0, r6, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A1CD2
	cmp r1, #0
	blt _080A1CD2
	ldr r0, _080A1CDC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A1CD2
	ldr r0, _080A1CE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A1CE4
_080A1CD2:
	movs r4, #0
	b _080A1CF2
	.align 2, 0
_080A1CD8: .4byte 0xFFFF0000
_080A1CDC: .4byte 0x030046A8
_080A1CE0: .4byte 0x030046AC
_080A1CE4:
	ldr r0, _080A1D04 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A1CF2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080A1D08
	adds r0, #4
	b _080A1D14
	.align 2, 0
_080A1D04: .4byte 0x030046A4
_080A1D08:
	ldr r0, _080A1D28 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A1D14:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080A1D2C
	cmp r3, #2
	beq _080A1D30
	b _080A1D34
	.align 2, 0
_080A1D28: .4byte 0x030046A4
_080A1D2C:
	ldrb r0, [r6, #4]
	b _080A1D32
_080A1D30:
	ldrb r0, [r6]
_080A1D32:
	subs r2, r2, r0
_080A1D34:
	add r1, sp, #8
	strh r2, [r1, #2]
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A1D5E
	cmp r1, #0
	blt _080A1D5E
	ldr r0, _080A1D64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A1D5E
	ldr r0, _080A1D68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A1D6C
_080A1D5E:
	movs r0, #0
	b _080A1D7A
	.align 2, 0
_080A1D64: .4byte 0x030046A8
_080A1D68: .4byte 0x030046AC
_080A1D6C:
	ldr r0, _080A1DD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A1D7A:
	adds r1, r5, #0
	adds r1, #0xc2
	strh r0, [r1]
	add r0, sp, #8
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #1
	adds r2, r5, #0
	adds r2, #0xc1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xb0
	ldrh r1, [r1]
	ldrb r3, [r2]
	movs r2, #0xff
	str r2, [sp]
	adds r2, #4
	str r2, [sp, #4]
	movs r2, #0
	bl Map_AddTileOverride
	adds r0, r5, #0
	add r1, sp, #8
	bl FUN_080a1b48
	adds r0, r5, #0
	adds r1, r7, #0
	add r2, sp, #8
	bl FUN_080a1bbc
	movs r0, #0x52
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A1DD4
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xc8
	str r0, [r1]
	b _080A1DDA
	.align 2, 0
_080A1DD0: .4byte 0x030046A4
_080A1DD4:
	adds r0, r5, #0
	adds r0, #0xc8
	str r1, [r0]
_080A1DDA:
	movs r0, #0
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a1de4
FUN_080a1de4: @ 0x080A1DE4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #8
	movs r1, #0xcc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A1E20
	ldr r1, _080A1E18 @ =FUN_080a1ae8
	ldr r2, _080A1E1C @ =FUN_080a1b28
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a1c44
	cmp r0, #0
	bge _080A1E20
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A1E22
	.align 2, 0
_080A1E18: .4byte FUN_080a1ae8
_080A1E1C: .4byte FUN_080a1b28
_080A1E20:
	adds r0, r4, #0
_080A1E22:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a1e28
FUN_080a1e28: @ 0x080A1E28
	push {r4, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x32]
	adds r2, r0, #1
	strh r2, [r3, #0x32]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A1E48
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	movs r0, #0
	strh r0, [r3, #0x30]
	b _080A1E70
_080A1E48:
	ldrh r0, [r3, #0x28]
	ldrh r4, [r3, #0x18]
	adds r0, r0, r4
	strh r0, [r3, #0x18]
	ldrh r0, [r3, #0x2a]
	ldrh r4, [r3, #0x1a]
	adds r0, r0, r4
	strh r0, [r3, #0x1a]
	ldrh r0, [r3, #0x2c]
	ldrh r4, [r3, #0x1c]
	adds r0, r0, r4
	strh r0, [r3, #0x1c]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r3, #0
	bl Particle_SetFrame
_080A1E70:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a1e78
FUN_080a1e78: @ 0x080A1E78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0xbd
	adds r0, r0, r7
	mov sl, r0
	ldrb r2, [r0]
	movs r0, #0x34
	adds r4, r2, #0
	muls r4, r0, r4
	adds r4, #0xc0
	adds r4, r7, r4
	adds r0, r4, #0
	movs r2, #2
	bl Particle_SetFrame
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r5, _080A1F50 @ =0x0203B400
	ldr r1, _080A1F54 @ =0x030046B8
	mov sb, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r3, _080A1F58 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r2, r7, #0
	adds r2, #0xac
	asrs r0, r0, #4
	movs r6, #0xff
	mov r8, r6
	mov r6, r8
	ands r0, r6
	ldrh r2, [r2]
	adds r0, r0, r2
	subs r0, #0x7f
	strh r0, [r4, #0x18]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0xae
	adds r2, r2, r7
	mov ip, r2
	movs r2, #0x3f
	ands r0, r2
	mov r6, ip
	ldrh r6, [r6]
	adds r0, r0, r6
	strh r0, [r4, #0x1a]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r2, r7, #0
	adds r2, #0xb0
	asrs r0, r0, #4
	mov r6, r8
	ands r0, r6
	ldrh r2, [r2]
	adds r0, r0, r2
	subs r0, #0x7f
	strh r0, [r4, #0x1c]
	movs r0, #0
	strh r0, [r4, #0x28]
	adds r1, #1
	ands r1, r3
	mov r2, sb
	str r1, [r2]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strh r0, [r4, #0x2a]
	movs r6, #0
	strh r6, [r4, #0x2c]
	strh r6, [r4, #0x32]
	movs r0, #1
	strh r0, [r4, #0x30]
	mov r1, sl
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080A1F42
	movs r0, #0
	strb r0, [r1]
_080A1F42:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A1F50: .4byte 0x0203B400
_080A1F54: .4byte 0x030046B8
_080A1F58: .4byte 0x000003FF

	thumb_func_start FUN_080a1f5c
FUN_080a1f5c: @ 0x080A1F5C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_080865c0
	adds r3, r0, #0
	cmp r3, #0
	beq _080A1FA2
	movs r2, #0
	ldrsh r1, [r3, r2]
	adds r2, r5, #0
	adds r2, #0xac
	movs r4, #0
	ldrsh r2, [r2, r4]
	subs r1, r1, r2
	cmp r1, #0
	bge _080A1F7E
	rsbs r1, r1, #0
_080A1F7E:
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r1, #4
	ldrsh r2, [r3, r1]
	adds r1, r5, #0
	adds r1, #0xb0
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r2, r1
	cmp r1, #0
	bge _080A1F96
	rsbs r1, r1, #0
_080A1F96:
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	cmp r4, #0x7f
	bhi _080A1FA2
	cmp r2, #0x7f
	bls _080A1FA6
_080A1FA2:
	movs r0, #0
	b _080A1FBA
_080A1FA6:
	adds r1, r4, #0
	muls r1, r4, r1
	adds r4, r2, #0
	muls r4, r2, r4
	adds r2, r4, #0
	adds r1, r1, r2
	ldr r2, _080A1FC0 @ =0x00003FFF
	cmp r1, r2
	bgt _080A1FBA
	movs r0, #1
_080A1FBA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A1FC0: .4byte 0x00003FFF

	thumb_func_start FUN_080a1fc4
FUN_080a1fc4: @ 0x080A1FC4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xa8
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A2040
	adds r0, r4, #0
	bl FUN_080a1f5c
	cmp r0, #0
	beq _080A200C
	ldr r0, _080A2034 @ =0x03002C00
	ldr r0, [r0]
	ldr r1, _080A2038 @ =0x000001F5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080A200C
	strh r0, [r5]
	movs r2, #0x98
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _080A1FFE
	movs r1, #0
	bl VM_ExecByID
_080A1FFE:
	movs r0, #1
	bl FUN_0808670c
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080A200C:
	adds r1, r4, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _080A203C @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080A2090
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r4, #0
	bl FUN_080a1e78
	b _080A2090
	.align 2, 0
_080A2034: .4byte 0x03002C00
_080A2038: .4byte 0x000001F5
_080A203C: .4byte 0x0000FFFF
_080A2040:
	adds r0, r4, #0
	bl FUN_080a1f5c
	adds r6, r0, #0
	cmp r6, #0
	bne _080A206C
	movs r1, #0x99
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080A205E
	movs r1, #0
	bl VM_ExecByID
_080A205E:
	movs r0, #0
	bl FUN_0808670c
	strh r6, [r5]
	ldr r0, _080A2098 @ =0x00000199
	bl PlaySound_082406e0
_080A206C:
	adds r1, r4, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _080A209C @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080A2090
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r4, #0
	bl FUN_080a1e78
_080A2090:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2098: .4byte 0x00000199
_080A209C: .4byte 0x0000FFFF

	thumb_func_start FUN_080a20a0
FUN_080a20a0: @ 0x080A20A0
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x18]
	adds r3, r2, #0
	adds r3, #0xaa
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080A20DC
	adds r0, r2, #0
	adds r0, #0xae
	ldrh r0, [r0]
	adds r0, #0x1e
	strh r0, [r2, #0x36]
	movs r0, #0
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xb4
	ldr r0, _080A20D8 @ =FUN_080a1fc4
	str r0, [r1]
	b _080A20E8
	.align 2, 0
_080A20D8: .4byte FUN_080a1fc4
_080A20DC:
	adds r3, r2, #0
	adds r3, #0xae
	lsls r0, r1, #1
	ldrh r3, [r3]
	adds r0, r0, r3
	strh r0, [r2, #0x36]
_080A20E8:
	adds r1, r2, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r3, _080A2110 @ =0x0000FFFF
	adds r1, r3, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080A210C
	adds r0, r2, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r2, #0
	bl FUN_080a1e78
_080A210C:
	pop {r0}
	bx r0
	.align 2, 0
_080A2110: .4byte 0x0000FFFF

	thumb_func_start FUN_080a2114
FUN_080a2114: @ 0x080A2114
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x18]
	ldr r0, [r2, #0x60]
	subs r1, #3
	ands r0, r1
	str r0, [r2, #0x60]
	adds r3, r2, #0
	adds r3, #0xaa
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _080A216C
	ldr r0, [r2, #0x60]
	subs r1, #1
	ands r0, r1
	str r0, [r2, #0x60]
	adds r0, r2, #0
	adds r0, #0x68
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #0
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xb4
	ldr r0, _080A2164 @ =FUN_080a20a0
	str r0, [r1]
	ldr r0, _080A2168 @ =0x0000032F
	bl PlaySound_082406e0
	b _080A218C
	.align 2, 0
_080A2164: .4byte FUN_080a20a0
_080A2168: .4byte 0x0000032F
_080A216C:
	ldr r0, [r2, #0x60]
	movs r1, #2
	orrs r0, r1
	str r0, [r2, #0x60]
	ldrh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x68
	strb r1, [r0]
	ldrh r0, [r3]
	adds r1, r2, #0
	adds r1, #0x69
	strb r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #2
	subs r1, #3
	strb r0, [r1]
_080A218C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a2190
FUN_080a2190: @ 0x080A2190
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
_080A2196:
	movs r0, #0x34
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, r1
	adds r0, #0xf0
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A21B6
	adds r0, r1, #0
	adds r0, #0xc0
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r1, [r1]
	bl FUN_080a1e28
_080A21B6:
	adds r5, #1
	cmp r5, #7
	ble _080A2196
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a21d0
FUN_080a21d0: @ 0x080A21D0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0x60
	bl AuxSprite_Remove
	adds r4, #0xc0
	movs r5, #7
_080A21E6:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080A21E6
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a21fc
FUN_080a21fc: @ 0x080A21FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldr r0, _080A2290 @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r6, #0
	adds r1, #0xb8
	str r0, [r1]
	movs r7, #0
	mov r8, r1
	movs r0, #4
	rsbs r0, r0, #0
	mov sl, r0
	movs r1, #1
	mov sb, r1
_080A2222:
	movs r0, #0x34
	adds r5, r7, #0
	muls r5, r0, r5
	adds r4, r5, #0
	adds r4, #0xc0
	adds r4, r6, r4
	mov r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	bl Particle_Add
	adds r0, r4, #0
	mov r1, sl
	mov r2, sl
	bl Particle_SetOffset
	mov r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #2
	bl Particle_SetFrame
	adds r0, r4, #0
	movs r1, #1
	bl Particle_SetPltt
	mov r1, sb
	strb r1, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	ldr r0, [r4]
	mov r1, sb
	orrs r0, r1
	str r0, [r4]
	adds r5, r6, r5
	adds r5, #0xf0
	movs r0, #0
	strh r0, [r5]
	adds r7, #1
	cmp r7, #7
	ble _080A2222
	adds r0, r6, #0
	adds r0, #0xbd
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strh r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2290: .4byte 0x00001C1E

	thumb_func_start FUN_080a2294
FUN_080a2294: @ 0x080A2294
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A2350
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0xac
	strh r0, [r4]
	bl VM_GetValue
	adds r5, r7, #0
	adds r5, #0xae
	strh r0, [r5]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0xb0
	strh r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sl, r4
	cmp r2, #0
	blt _080A22F0
	cmp r1, #0
	blt _080A22F0
	ldr r0, _080A22F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A22F0
	ldr r0, _080A22F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A22FC
_080A22F0:
	movs r6, #0
	b _080A230A
	.align 2, 0
_080A22F4: .4byte 0x030046A8
_080A22F8: .4byte 0x030046AC
_080A22FC:
	ldr r0, _080A231C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080A230A:
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080A2320
	adds r0, #4
	b _080A232C
	.align 2, 0
_080A231C: .4byte 0x030046A4
_080A2320:
	ldr r0, _080A2340 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A232C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A2344
	cmp r2, #2
	beq _080A2348
	b _080A234C
	.align 2, 0
_080A2340: .4byte 0x030046A4
_080A2344:
	ldrb r0, [r4, #4]
	b _080A234A
_080A2348:
	ldrb r0, [r4]
_080A234A:
	subs r1, r1, r0
_080A234C:
	strh r1, [r5]
	b _080A2362
_080A2350:
	adds r1, r7, #0
	adds r1, #0xac
	strh r2, [r1]
	adds r0, r7, #0
	adds r0, #0xae
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	mov sl, r1
_080A2362:
	adds r4, r7, #0
	adds r4, #0x44
	ldr r0, _080A2428 @ =0x00000BA8
	mov sb, r0
	adds r0, r4, #0
	mov r1, sb
	bl Video_GetAuxSprite
	adds r5, r7, #0
	adds r5, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r6, #6
	strh r6, [r5, #0x10]
	adds r0, r4, #0
	movs r1, #0x63
	bl Video_SetAuxSpritePltt
	ldr r0, [r7, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r7, #0x18]
	movs r1, #3
	mov r8, r1
	mov r2, r8
	strb r2, [r7, #0x1f]
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldrh r0, [r7, #0x36]
	adds r0, #0x1e
	strh r0, [r7, #0x36]
	adds r4, #0x48
	adds r0, r4, #0
	mov r1, sb
	bl Video_GetAuxSprite
	adds r5, #0x48
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	strh r6, [r5, #0x10]
	adds r0, r4, #0
	movs r1, #0x61
	bl Video_SetAuxSpritePltt
	ldr r0, [r7, #0x60]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r7, #0x60]
	adds r0, r7, #0
	adds r0, #0x67
	mov r1, r8
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0x7c
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl FUN_080a21fc
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A2430
	bl VM_GetValue
	cmp r0, #0
	beq _080A2430
	ldr r0, [r7, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x18]
	ldr r0, [r7, #0x60]
	orrs r0, r1
	str r0, [r7, #0x60]
	adds r1, r7, #0
	adds r1, #0xb4
	ldr r0, _080A242C @ =FUN_080a2114
	str r0, [r1]
	movs r0, #0xaf
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080A2438
	.align 2, 0
_080A2428: .4byte 0x00000BA8
_080A242C: .4byte FUN_080a2114
_080A2430:
	adds r1, r7, #0
	adds r1, #0xb4
	ldr r0, _080A2458 @ =FUN_080a1fc4
	str r0, [r1]
_080A2438:
	adds r1, r7, #0
	adds r1, #0xaa
	movs r0, #0
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_080a1f5c
	adds r1, r0, #0
	cmp r1, #0
	beq _080A245C
	adds r1, r7, #0
	adds r1, #0xa8
	movs r0, #1
	strh r0, [r1]
	adds r4, r1, #0
	b _080A2464
	.align 2, 0
_080A2458: .4byte FUN_080a1fc4
_080A245C:
	adds r0, r7, #0
	adds r0, #0xa8
	strh r1, [r0]
	adds r4, r0, #0
_080A2464:
	movs r0, #0x69
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A247E
	bl VM_GetValue
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A2486
_080A247E:
	movs r3, #0x98
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A2486:
	movs r0, #0x6f
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A24A0
	bl VM_GetValue
	movs r2, #0x99
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A24A8
_080A24A0:
	movs r3, #0x99
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A24A8:
	adds r0, r7, #0
	bl FUN_080a1f5c
	cmp r0, #0
	beq _080A24BC
	movs r0, #1
	strh r0, [r4]
	bl FUN_0808670c
	b _080A24C4
_080A24BC:
	strh r0, [r4]
	movs r0, #0
	bl FUN_0808670c
_080A24C4:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a24d4
FUN_080a24d4: @ 0x080A24D4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x9a
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A2514
	ldr r1, _080A250C @ =FUN_080a2190
	ldr r2, _080A2510 @ =FUN_080a21d0
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a2294
	cmp r0, #0
	bge _080A2514
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A2516
	.align 2, 0
_080A250C: .4byte FUN_080a2190
_080A2510: .4byte FUN_080a21d0
_080A2514:
	adds r0, r4, #0
_080A2516:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a251c
FUN_080a251c: @ 0x080A251C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x29
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080A2542
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r0, r4, #0
	adds r0, #0x28
	strb r2, [r0]
	b _080A25C0
_080A2542:
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x2e]
	ldrh r1, [r4, #0x1a]
	adds r0, r0, r1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x30]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	ldr r0, _080A2584 @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r0, #0
	ldrb r2, [r5]
	lsrs r2, r2, #2
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r4, #0
	bl Particle_SetFrame
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	cmp r0, #0
	blt _080A2588
	asrs r0, r0, #4
	b _080A258E
	.align 2, 0
_080A2584: .4byte 0x00001C1E
_080A2588:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_080A258E:
	strh r0, [r4, #0x2c]
	movs r0, #0x2e
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	cmp r0, #0
	blt _080A25A0
	asrs r0, r0, #4
	b _080A25A6
_080A25A0:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_080A25A6:
	strh r0, [r4, #0x2e]
	movs r0, #0x30
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	cmp r0, #0
	blt _080A25B8
	asrs r0, r0, #4
	b _080A25BE
_080A25B8:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_080A25BE:
	strh r0, [r4, #0x30]
_080A25C0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a25c8
FUN_080a25c8: @ 0x080A25C8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0, #0x18]
	str r2, [r0, #0x1c]
	ldr r6, _080A266C @ =0x0203B400
	ldr r1, _080A2670 @ =0x030046B8
	mov sb, r1
	ldr r2, [r1]
	adds r2, #1
	ldr r4, _080A2674 @ =0x000003FF
	ands r2, r4
	lsls r1, r2, #1
	adds r1, r1, r6
	ldrh r3, [r1]
	ldrh r1, [r0, #0x18]
	subs r1, #0xf
	movs r5, #0x1f
	ands r3, r5
	adds r1, r1, r3
	movs r3, #0
	mov r8, r3
	strh r1, [r0, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r3, r2, #1
	adds r3, r3, r6
	movs r7, #0xc0
	lsls r7, r7, #2
	adds r1, r7, #0
	ldrh r7, [r0, #0x1a]
	adds r1, r1, r7
	ldrb r3, [r3]
	adds r1, r1, r3
	strh r1, [r0, #0x1a]
	adds r2, #1
	ands r2, r4
	lsls r1, r2, #1
	adds r1, r1, r6
	ldrh r3, [r1]
	ldrh r1, [r0, #0x1c]
	subs r1, #0xf
	ands r3, r5
	adds r1, r1, r3
	strh r1, [r0, #0x1c]
	adds r3, r0, #0
	adds r3, #0x29
	movs r1, #0x18
	strb r1, [r3]
	mov r1, r8
	strh r1, [r0, #0x2c]
	adds r2, #1
	ands r2, r4
	mov r3, sb
	str r2, [r3]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r1, [r2]
	ands r1, r5
	adds r1, #0x20
	rsbs r1, r1, #0
	strh r1, [r0, #0x2e]
	mov r7, r8
	strh r7, [r0, #0x30]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	adds r0, #0x28
	movs r1, #1
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A266C: .4byte 0x0203B400
_080A2670: .4byte 0x030046B8
_080A2674: .4byte 0x000003FF

	thumb_func_start FUN_080a2678
FUN_080a2678: @ 0x080A2678
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0, #0x18]
	str r2, [r0, #0x1c]
	ldr r6, _080A2710 @ =0x0203B400
	ldr r1, _080A2714 @ =0x030046B8
	mov sb, r1
	ldr r3, [r1]
	adds r3, #1
	ldr r4, _080A2718 @ =0x000003FF
	ands r3, r4
	lsls r1, r3, #1
	adds r1, r1, r6
	ldrh r2, [r1]
	ldrh r1, [r0, #0x18]
	subs r1, #0xf
	movs r5, #0x1f
	ands r2, r5
	adds r1, r1, r2
	movs r2, #0
	mov r8, r2
	strh r1, [r0, #0x18]
	adds r3, #1
	ands r3, r4
	lsls r2, r3, #1
	adds r2, r2, r6
	ldrh r1, [r0, #0x1a]
	ldrb r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #0x1a]
	adds r3, #1
	ands r3, r4
	lsls r1, r3, #1
	adds r1, r1, r6
	ldrh r2, [r1]
	ldrh r1, [r0, #0x1c]
	subs r1, #0xf
	ands r2, r5
	adds r1, r1, r2
	strh r1, [r0, #0x1c]
	adds r2, r0, #0
	adds r2, #0x29
	movs r1, #0x18
	strb r1, [r2]
	mov r1, r8
	strh r1, [r0, #0x2c]
	adds r3, #1
	ands r3, r4
	mov r2, sb
	str r3, [r2]
	lsls r3, r3, #1
	adds r3, r3, r6
	ldrh r1, [r3]
	ands r1, r5
	adds r1, #0x18
	strh r1, [r0, #0x2e]
	mov r1, r8
	strh r1, [r0, #0x30]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	adds r0, #0x28
	movs r1, #1
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2710: .4byte 0x0203B400
_080A2714: .4byte 0x030046B8
_080A2718: .4byte 0x000003FF

	thumb_func_start FUN_080a271c
FUN_080a271c: @ 0x080A271C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A276C @ =0x030046A0
	ldr r3, [r0]
	movs r0, #0x30
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x98
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	cmp r2, #0
	bge _080A2738
	rsbs r2, r2, #0
_080A2738:
	movs r1, #0x34
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0x9c
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r0, r1
	cmp r1, #0
	bge _080A274C
	rsbs r1, r1, #0
_080A274C:
	cmp r2, #0x60
	bgt _080A2770
	cmp r1, #0x60
	bgt _080A2770
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x90
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080A2770
	movs r0, #1
	b _080A2772
	.align 2, 0
_080A276C: .4byte 0x030046A0
_080A2770:
	movs r0, #0
_080A2772:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a2778
FUN_080a2778: @ 0x080A2778
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080865c0
	adds r3, r0, #0
	cmp r3, #0
	beq _080A27FC
	ldr r0, _080A27F0 @ =0x03002C00
	ldr r1, [r0]
	ldrb r0, [r1, #0x1a]
	cmp r0, #4
	bne _080A27FC
	ldr r2, _080A27F4 @ =0x000001F5
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bhi _080A27FC
	movs r0, #2
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x9a
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _080A27AE
	rsbs r1, r1, #0
_080A27AE:
	cmp r1, #0xff
	bgt _080A27FC
	movs r0, #0
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x98
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	movs r0, #4
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x9c
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	movs r0, #0xbe
	lsls r0, r0, #1
	cmp r2, r0
	bgt _080A27FC
	cmp r1, r0
	bgt _080A27FC
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	ldr r1, _080A27F8 @ =0x00023410
	cmp r0, r1
	bgt _080A27FC
	movs r0, #1
	b _080A27FE
	.align 2, 0
_080A27F0: .4byte 0x03002C00
_080A27F4: .4byte 0x000001F5
_080A27F8: .4byte 0x00023410
_080A27FC:
	movs r0, #0
_080A27FE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a2804
FUN_080a2804: @ 0x080A2804
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r4, r3, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A2816
	b _080A29E8
_080A2816:
	cmp r0, #2
	bhi _080A2864
	adds r2, r3, #0
	adds r2, #0xe8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	subs r2, #0x4e
	ldrh r1, [r4]
	movs r0, #2
	subs r0, r0, r1
	movs r1, #0xab
	muls r0, r1, r0
	ldr r1, _080A2860 @ =0x00000402
	adds r0, r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r3, r2
	strh r0, [r1]
	movs r4, #0x8a
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r5, #0xa0
	lsls r5, r5, #1
	adds r1, r3, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080A28C4
	.align 2, 0
_080A2860: .4byte 0x00000402
_080A2864:
	cmp r0, #4
	bhi _080A28D4
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0x9a
	adds r0, r0, r3
	mov ip, r0
	ldr r1, _080A28D0 @ =0x00000402
	adds r0, r1, #0
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r5, #0x83
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldrh r1, [r4]
	movs r0, #4
	subs r0, r0, r1
	movs r1, #0xab
	muls r0, r1, r0
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r0, r1
	mov r2, ip
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r4, #0x99
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	adds r5, #0x3a
	adds r2, r3, r5
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_080A28C4:
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r1, [r0]
	adds r0, #2
	strh r1, [r0, #0x10]
	b _080A2A0C
	.align 2, 0
_080A28D0: .4byte 0x00000402
_080A28D4:
	cmp r0, #6
	bhi _080A2960
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0x9a
	adds r0, r0, r3
	mov ip, r0
	ldr r1, _080A295C @ =0x00000402
	adds r0, r1, #0
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r5, #0x83
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r1, #0
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r5, #0x99
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldrh r1, [r4]
	movs r0, #6
	subs r0, r0, r1
	movs r1, #0xab
	muls r0, r1, r0
	adds r1, #0xab
	adds r0, r0, r1
	mov r2, ip
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r1, [r0]
	adds r0, #2
	strh r1, [r0, #0x10]
	adds r1, r3, #0
	adds r1, #0x57
	movs r0, #3
	strb r0, [r1]
	b _080A2A0C
	.align 2, 0
_080A295C: .4byte 0x00000402
_080A2960:
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r5, #0x9a
	adds r5, r5, r3
	mov ip, r5
	ldr r1, _080A29E4 @ =0x00000402
	adds r0, r1, #0
	ldrh r4, [r5]
	adds r0, r0, r4
	movs r5, #0x83
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r1, #0
	mov r4, ip
	ldrh r4, [r4]
	adds r0, r0, r4
	adds r5, #0x2c
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r1, #0
	mov r2, ip
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r0, [r0]
	adds r1, r3, #0
	adds r1, #0x50
	adds r0, #8
	strh r0, [r1, #0x10]
	ldr r0, [r3, #0x50]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r3, #0x50]
	adds r1, r3, #0
	adds r1, #0x57
	movs r0, #1
	strb r0, [r1]
	b _080A2A0C
	.align 2, 0
_080A29E4: .4byte 0x00000402
_080A29E8:
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x8a
	lsls r5, r5, #1
	adds r1, r3, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_080A2A0C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a2a14
FUN_080a2a14: @ 0x080A2A14
	movs r3, #0xe1
	lsls r3, r3, #2
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080A2A28 @ =0x00000382
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080A2A28: .4byte 0x00000382

	thumb_func_start FUN_080a2a2c
FUN_080a2a2c: @ 0x080A2A2C
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x50]
	adds r0, r2, #0
	adds r0, #0x7c
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r1, r2, r3
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
	pop {r0}
	bx r0

	thumb_func_start FUN_080a2a4c
FUN_080a2a4c: @ 0x080A2A4C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A2A88 @ =0x00000382
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A2A68
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_080A2A68:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #7
	bhi _080A2A78
	adds r0, #1
	strh r0, [r1]
_080A2A78:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0x16
	bhi _080A2A8C
	adds r0, #2
	b _080A2A8E
	.align 2, 0
_080A2A88: .4byte 0x00000382
_080A2A8C:
	movs r0, #0x18
_080A2A8E:
	strb r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r4, r1
	ldrb r0, [r2]
	cmp r0, #0
	bne _080A2AA6
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
	b _080A2AC0
_080A2AA6:
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
_080A2AC0:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #7
	bls _080A2ADE
	adds r0, r4, #0
	adds r0, #0x7c
	subs r2, #2
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	b _080A2B06
_080A2ADE:
	cmp r0, #0
	beq _080A2AF6
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl Video_SetAuxSpritePltt
	b _080A2B06
_080A2AF6:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
_080A2B06:
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x17
	bls _080A2B24
	ldr r1, _080A2B2C @ =FUN_080a2b30
	adds r0, r4, #0
	bl FUN_080a2a14
	adds r0, r4, #0
	adds r0, #0x18
	movs r1, #1
	bl MsgQueue_EndWait
_080A2B24:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2B2C: .4byte FUN_080a2b30

	thumb_func_start FUN_080a2b30
FUN_080a2b30: @ 0x080A2B30
	push {lr}
	adds r3, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r2, r3, r0
	movs r0, #0x18
	strb r0, [r2]
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #8
	strh r0, [r1]
	ldr r0, [r3, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x50]
	adds r0, r3, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r3, #0
	adds r1, #0x6e
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r3, r2
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	pop {r0}
	bx r0

	thumb_func_start FUN_080a2b78
FUN_080a2b78: @ 0x080A2B78
	push {lr}
	adds r3, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #1
	bls _080A2B8C
	subs r0, #2
	b _080A2B8E
_080A2B8C:
	movs r0, #0
_080A2B8E:
	strb r0, [r1]
	adds r1, r3, #0
	adds r1, #0x9a
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrh r1, [r1]
	ldrb r2, [r0]
	adds r1, r1, r2
	adds r2, r3, #0
	adds r2, #0x6e
	strh r1, [r2]
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A2BCE
	ldr r0, [r3, #0x50]
	ldr r1, _080A2BD4 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r3, #0x50]
	adds r1, r3, #0
	adds r1, #0x57
	movs r0, #3
	strb r0, [r1]
	adds r2, #0x32
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080A2BD8 @ =FUN_080a2bdc
	adds r0, r3, #0
	bl FUN_080a2a14
_080A2BCE:
	pop {r0}
	bx r0
	.align 2, 0
_080A2BD4: .4byte 0xFFFFFDFF
_080A2BD8: .4byte FUN_080a2bdc

	thumb_func_start FUN_080a2bdc
FUN_080a2bdc: @ 0x080A2BDC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #6
	bhi _080A2BF8
	adds r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A2C18
_080A2BF8:
	ldr r0, _080A2C20 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080A2C18
	ldr r0, _080A2C24 @ =0x0000015F
	bl PlaySound_082406e0
	ldr r1, _080A2C28 @ =FUN_080a2c2c
	adds r0, r4, #0
	bl FUN_080a2a14
_080A2C18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2C20: .4byte 0x00000382
_080A2C24: .4byte 0x0000015F
_080A2C28: .4byte FUN_080a2c2c

	thumb_func_start FUN_080a2c2c
FUN_080a2c2c: @ 0x080A2C2C
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A2C50 @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A2C4A
	ldr r1, _080A2C54 @ =FUN_080a2c58
	adds r0, r2, #0
	bl FUN_080a2a14
_080A2C4A:
	pop {r0}
	bx r0
	.align 2, 0
_080A2C50: .4byte 0x00000382
_080A2C54: .4byte FUN_080a2c58

	thumb_func_start FUN_080a2c58
FUN_080a2c58: @ 0x080A2C58
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080A2CA8 @ =0x00000382
	adds r0, r4, r1
	ldrh r2, [r0]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x1f
	bhi _080A2C88
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A2C88
	lsrs r1, r1, #0x12
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0x98
	bl FUN_080a2678
_080A2C88:
	ldr r0, _080A2CA8 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bne _080A2CA2
	ldr r1, _080A2CAC @ =FUN_080a2cb0
	adds r0, r4, #0
	bl FUN_080a2a14
_080A2CA2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2CA8: .4byte 0x00000382
_080A2CAC: .4byte FUN_080a2cb0

	thumb_func_start FUN_080a2cb0
FUN_080a2cb0: @ 0x080A2CB0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	movs r3, #2
	rsbs r3, r3, #0
	ands r0, r3
	str r0, [r4, #0x50]
	adds r2, r4, #0
	adds r2, #0x6e
	movs r0, #0
	ldrsh r1, [r2, r0]
	adds r0, r4, #0
	adds r0, #0x9a
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r0, #0x16
	cmp r1, r0
	bge _080A2CDA
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
_080A2CDA:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A2CF2
	subs r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A2D0E
_080A2CF2:
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	ldr r1, _080A2D14 @ =FUN_080a2e20
	adds r0, r4, #0
	bl FUN_080a2a14
	adds r0, r4, #0
	adds r0, #0x18
	movs r1, #1
	bl MsgQueue_EndWait
_080A2D0E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2D14: .4byte FUN_080a2e20

	thumb_func_start FUN_080a2d18
FUN_080a2d18: @ 0x080A2D18
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A2D94 @ =0x00000382
	adds r5, r4, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x3f
	bhi _080A2D98
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r2, #2
	orrs r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	ldrh r0, [r5]
	adds r2, r4, #0
	adds r2, #0x58
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x59
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r3, r4, #0
	adds r3, #0x56
	strb r0, [r3]
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0xa8
	strb r1, [r0]
	ldrb r0, [r2]
	adds r1, r4, #0
	adds r1, #0xa9
	strb r0, [r1]
	ldrb r0, [r3]
	subs r1, #3
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	adds r0, #0x16
	subs r1, #0x38
	strh r0, [r1]
	b _080A2E14
	.align 2, 0
_080A2D94: .4byte 0x00000382
_080A2D98:
	cmp r3, #0x40
	bne _080A2DC4
	ldr r0, [r4, #0x50]
	movs r2, #3
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x58
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #0x4f
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	b _080A2E14
_080A2DC4:
	cmp r3, #0x4f
	bls _080A2E14
	adds r1, r4, #0
	adds r1, #0x6e
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	adds r1, #0x2c
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	ble _080A2DF4
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl Video_SetAuxSpritePltt
	b _080A2E14
_080A2DF4:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
	ldr r1, _080A2E1C @ =FUN_080a2e20
	adds r0, r4, #0
	bl FUN_080a2a14
_080A2E14:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2E1C: .4byte FUN_080a2e20

	thumb_func_start FUN_080a2e20
FUN_080a2e20: @ 0x080A2E20
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080A2E94 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A2E40
	ldr r0, _080A2E98 @ =0x0000036A
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #9
	bhi _080A2E40
	adds r0, #1
	strh r0, [r1]
_080A2E40:
	adds r0, r4, #0
	bl FUN_080a271c
	adds r6, r0, #0
	cmp r6, #0
	bne _080A2E4E
	b _080A2F4C
_080A2E4E:
	ldr r1, _080A2E9C @ =0x00000369
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A2EAC
	movs r2, #1
	ldr r0, _080A2EA0 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	bne _080A2E66
	b _080A2F86
_080A2E66:
	ldr r0, _080A2EA4 @ =0x03002BE0
	ldr r0, [r0]
	adds r1, #0x13
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	bne _080A2E76
	b _080A2F86
_080A2E76:
	cmp r0, #0x19
	bne _080A2E7C
	b _080A2F86
_080A2E7C:
	ldr r0, _080A2EA8 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _080A2E8A
	b _080A2F86
_080A2E8A:
	movs r0, #0x92
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080A2F86
	.align 2, 0
_080A2E94: .4byte 0x030047A4
_080A2E98: .4byte 0x0000036A
_080A2E9C: .4byte 0x00000369
_080A2EA0: .4byte 0x03002BC0
_080A2EA4: .4byte 0x03002BE0
_080A2EA8: .4byte 0x030044E0
_080A2EAC:
	adds r5, r4, #0
	adds r5, #0x4c
	ldrh r0, [r5]
	cmp r0, #1
	beq _080A2EC2
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strh r0, [r5]
_080A2EC2:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #7
	bhi _080A2ED2
	adds r0, #1
	strh r0, [r1]
_080A2ED2:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0x16
	bhi _080A2EE2
	adds r0, #2
	b _080A2EE4
_080A2EE2:
	movs r0, #0x18
_080A2EE4:
	strb r0, [r1]
	movs r2, #1
	ldr r0, _080A2F3C @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080A2F86
	ldr r0, _080A2F40 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080A2F86
	ldr r0, _080A2F44 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A2F86
	subs r1, #0x16
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #9
	bls _080A2F86
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #8
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x98
	adds r0, r2, #0
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	ldr r1, _080A2F48 @ =FUN_080a3004
	adds r0, r4, #0
	bl FUN_080a2a14
	b _080A2F86
	.align 2, 0
_080A2F3C: .4byte 0x03002BC0
_080A2F40: .4byte 0x030044E0
_080A2F44: .4byte 0x03002BE0
_080A2F48: .4byte FUN_080a3004
_080A2F4C:
	adds r5, r4, #0
	adds r5, #0x4c
	ldrh r0, [r5]
	cmp r0, #0
	beq _080A2F5E
	ldr r0, _080A2F80 @ =0x00000199
	bl PlaySound_082406e0
	strh r6, [r5]
_080A2F5E:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A2F6E
	subs r0, #1
	strh r0, [r1]
_080A2F6E:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #2
	bls _080A2F84
	subs r0, #2
	strb r0, [r1]
	b _080A2F86
	.align 2, 0
_080A2F80: .4byte 0x00000199
_080A2F84:
	strb r6, [r1]
_080A2F86:
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r4, r1
	ldrb r0, [r2]
	cmp r0, #0
	bne _080A2F9C
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
	b _080A2FB6
_080A2F9C:
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
_080A2FB6:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #7
	bls _080A2FD4
	adds r0, r4, #0
	adds r0, #0x7c
	subs r2, #2
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	b _080A2FFC
_080A2FD4:
	cmp r0, #0
	beq _080A2FEC
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl Video_SetAuxSpritePltt
	b _080A2FFC
_080A2FEC:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
_080A2FFC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a3004
FUN_080a3004: @ 0x080A3004
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #1
	bls _080A3018
	subs r0, #2
	b _080A301A
_080A3018:
	movs r0, #0
_080A301A:
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x9a
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r1, [r1]
	ldrb r2, [r0]
	adds r1, r1, r2
	adds r2, r4, #0
	adds r2, #0x6e
	strh r1, [r2]
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A30A6
	ldr r0, _080A30AC @ =0x03002BE0
	ldr r1, [r0]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A30A6
	adds r0, r1, #0
	movs r1, #4
	movs r2, #0
	bl FUN_0807c200
	ldr r0, _080A30B0 @ =0x000001C3
	adds r5, r4, r0
	movs r0, #0
	strb r0, [r5]
	adds r0, r4, #0
	bl FUN_080a2778
	cmp r0, #0
	beq _080A3070
	bl FUN_08086ab8
	cmp r0, #0
	beq _080A3070
	movs r0, #1
	strb r0, [r5]
_080A3070:
	ldr r0, [r4, #0x50]
	ldr r1, _080A30B4 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0x57
	movs r0, #3
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080A30B8 @ =FUN_080a30bc
	adds r0, r4, #0
	bl FUN_080a2a14
	movs r1, #0xdb
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080A30A6
	movs r1, #0
	bl VM_ExecByID
_080A30A6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A30AC: .4byte 0x03002BE0
_080A30B0: .4byte 0x000001C3
_080A30B4: .4byte 0xFFFFFDFF
_080A30B8: .4byte FUN_080a30bc

	thumb_func_start FUN_080a30bc
FUN_080a30bc: @ 0x080A30BC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #6
	bhi _080A30D8
	adds r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A30F8
_080A30D8:
	ldr r0, _080A3100 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080A30F8
	ldr r0, _080A3104 @ =0x0000015F
	bl PlaySound_082406e0
	ldr r1, _080A3108 @ =FUN_080a310c
	adds r0, r4, #0
	bl FUN_080a2a14
_080A30F8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3100: .4byte 0x00000382
_080A3104: .4byte 0x0000015F
_080A3108: .4byte FUN_080a310c

	thumb_func_start FUN_080a310c
FUN_080a310c: @ 0x080A310C
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A3130 @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A312A
	ldr r1, _080A3134 @ =FUN_080a3138
	adds r0, r2, #0
	bl FUN_080a2a14
_080A312A:
	pop {r0}
	bx r0
	.align 2, 0
_080A3130: .4byte 0x00000382
_080A3134: .4byte FUN_080a3138

	thumb_func_start FUN_080a3138
FUN_080a3138: @ 0x080A3138
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080A31D0 @ =0x00000382
	adds r0, r4, r1
	ldrh r2, [r0]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x1f
	bhi _080A316A
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A316A
	lsrs r1, r1, #0x12
	movs r0, #0x34
	muls r0, r1, r0
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0x98
	bl FUN_080a2678
_080A316A:
	ldr r0, _080A31D0 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bne _080A31C6
	movs r1, #0xdd
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A31AA
	ldr r1, _080A31D4 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r3, sp
	str r3, [r1, #4]
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r2, #0
	bl VM_ExecByID
_080A31AA:
	ldr r1, _080A31D8 @ =0x000001C3
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A31C6
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _080A31C6
	movs r1, #0
	bl VM_ExecByID
_080A31C6:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A31D0: .4byte 0x00000382
_080A31D4: .4byte 0xFFFF0000
_080A31D8: .4byte 0x000001C3

	thumb_func_start FUN_080a31dc
FUN_080a31dc: @ 0x080A31DC
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A3200 @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080A31FA
	ldr r1, _080A3204 @ =FUN_080a3208
	adds r0, r2, #0
	bl FUN_080a2a14
_080A31FA:
	pop {r0}
	bx r0
	.align 2, 0
_080A3200: .4byte 0x00000382
_080A3204: .4byte FUN_080a3208

	thumb_func_start FUN_080a3208
FUN_080a3208: @ 0x080A3208
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A326C @ =0x00000382
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0x10
	bne _080A3222
	ldr r0, _080A3270 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #4
	movs r2, #0
	bl FUN_0807c36c
_080A3222:
	ldrh r2, [r5]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x1f
	bhi _080A324A
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A324A
	lsrs r1, r1, #0x12
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0x98
	bl FUN_080a25c8
_080A324A:
	ldr r0, _080A326C @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _080A3264
	ldr r1, _080A3274 @ =FUN_080a3278
	adds r0, r4, #0
	bl FUN_080a2a14
_080A3264:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A326C: .4byte 0x00000382
_080A3270: .4byte 0x03002BE0
_080A3274: .4byte FUN_080a3278

	thumb_func_start FUN_080a3278
FUN_080a3278: @ 0x080A3278
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A329C @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A3296
	ldr r1, _080A32A0 @ =FUN_080a32a4
	adds r0, r2, #0
	bl FUN_080a2a14
_080A3296:
	pop {r0}
	bx r0
	.align 2, 0
_080A329C: .4byte 0x00000382
_080A32A0: .4byte FUN_080a32a4

	thumb_func_start FUN_080a32a4
FUN_080a32a4: @ 0x080A32A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r4, #0x50]
	adds r2, r4, #0
	adds r2, #0x6e
	movs r0, #0
	ldrsh r1, [r2, r0]
	adds r0, r4, #0
	adds r0, #0x9a
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, #0x16
	cmp r1, r0
	bge _080A32CE
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
_080A32CE:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A32E6
	subs r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A3336
_080A32E6:
	ldr r0, _080A3314 @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807d118
	bl FUN_080a6edc
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A331C
	ldr r1, _080A3318 @ =FUN_080a3340
	adds r0, r4, #0
	bl FUN_080a2a14
	b _080A3324
	.align 2, 0
_080A3314: .4byte 0x03002BE0
_080A3318: .4byte FUN_080a3340
_080A331C:
	ldr r1, _080A333C @ =FUN_080a2e20
	adds r0, r4, #0
	bl FUN_080a2a14
_080A3324:
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _080A3336
	movs r1, #0
	bl VM_ExecByID
_080A3336:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A333C: .4byte FUN_080a2e20

	thumb_func_start FUN_080a3340
FUN_080a3340: @ 0x080A3340
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #2
	bls _080A3370
	subs r0, #2
	strb r0, [r2]
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
	b _080A3378
_080A3370:
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
_080A3378:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A3388
	subs r0, #1
	strh r0, [r1]
_080A3388:
	ldrh r0, [r1]
	cmp r0, #7
	bls _080A33A2
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	b _080A33CA
_080A33A2:
	cmp r0, #0
	beq _080A33BA
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl Video_SetAuxSpritePltt
	b _080A33CA
_080A33BA:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
_080A33CA:
	ldr r0, _080A3424 @ =0x00000382
	adds r3, r4, r0
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bhi _080A3428
	ldr r0, [r4, #0x50]
	movs r2, #2
	orrs r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r1, [r3]
	movs r0, #0x40
	subs r0, r0, r1
	adds r2, r4, #0
	adds r2, #0x58
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x59
	strb r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r3, r4, #0
	adds r3, #0x56
	strb r0, [r3]
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0xa8
	strb r1, [r0]
	ldrb r0, [r2]
	adds r1, r4, #0
	adds r1, #0xa9
	strb r0, [r1]
	ldrb r1, [r3]
	adds r0, r4, #0
	adds r0, #0xa6
	strb r1, [r0]
	b _080A3440
	.align 2, 0
_080A3424: .4byte 0x00000382
_080A3428:
	ldr r0, [r4, #0x50]
	movs r2, #1
	orrs r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	bl KillEntity
_080A3440:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a3448
FUN_080a3448: @ 0x080A3448
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0x18
	movs r5, #0
	ldr r2, _080A3494 @ =0x03002B4C
	ldr r1, [r2]
	adds r1, #0x24
	adds r0, #0x1e
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	bge _080A34C4
	mov r8, r2
_080A346A:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r6, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl MsgQueue_BeginWait
	ldrb r0, [r4, #6]
	cmp r0, #7
	beq _080A3498
	cmp r0, #8
	beq _080A34A8
	b _080A34B0
	.align 2, 0
_080A3494: .4byte 0x03002B4C
_080A3498:
	adds r0, r7, #0
	ldr r1, _080A34A4 @ =FUN_080a2a4c
	bl FUN_080a2a14
	b _080A34B0
	.align 2, 0
_080A34A4: .4byte FUN_080a2a4c
_080A34A8:
	adds r0, r7, #0
	ldr r1, _080A34D0 @ =FUN_080a2b78
	bl FUN_080a2a14
_080A34B0:
	adds r5, #1
	mov r0, r8
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r6, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	blt _080A346A
_080A34C4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A34D0: .4byte FUN_080a2b78

	thumb_func_start FUN_080a34d4
FUN_080a34d4: @ 0x080A34D4
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080a3448
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r5, #0
_080A34EC:
	movs r0, #0x34
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, r1
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A350A
	subs r2, #0x28
	adds r0, r1, r2
	adds r0, r4, r0
	bl FUN_080a251c
_080A350A:
	adds r5, #1
	cmp r5, #7
	ble _080A34EC
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a3518
FUN_080a3518: @ 0x080A3518
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r0, #0x50
	bl AuxSprite_Remove
	adds r0, r6, #0
	adds r0, #0xa0
	bl AuxSprite_Remove
	adds r4, r6, #0
	adds r4, #0xe8
	movs r5, #2
_080A3530:
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _080A3530
	adds r7, r6, #0
	adds r7, #0x18
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #7
_080A354A:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080A354A
	adds r0, r7, #0
	bl MsgQueue_Unregister
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a3568
FUN_080a3568: @ 0x080A3568
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _080A35F8 @ =0x00001C1E
	mov sb, r0
	movs r0, #0
	mov sl, r0
	subs r0, #4
	mov r8, r0
_080A3582:
	movs r0, #0x34
	adds r5, r7, #0
	muls r5, r0, r5
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r5, r0
	adds r4, r6, r4
	mov r0, sb
	bl GetParticleGroup
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #1
	bl Particle_Add
	adds r0, r4, #0
	mov r1, r8
	mov r2, r8
	bl Particle_SetOffset
	adds r0, r4, #0
	movs r1, #1
	bl Particle_SetPltt
	mov r0, sb
	bl GetParticleGroup
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #2
	bl Particle_SetFrame
	movs r0, #1
	strb r0, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	adds r0, r6, #0
	adds r0, #0x98
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	adds r5, r6, r5
	movs r0, #0xf8
	lsls r0, r0, #1
	adds r5, r5, r0
	mov r0, sl
	strb r0, [r5]
	adds r7, #1
	cmp r7, #7
	ble _080A3582
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A35F8: .4byte 0x00001C1E

	thumb_func_start FUN_080a35fc
FUN_080a35fc: @ 0x080A35FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	str r1, [sp]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A36BC
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0x98
	strh r0, [r4]
	bl VM_GetValue
	adds r5, r7, #0
	adds r5, #0x9a
	strh r0, [r5]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x9c
	strh r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0xc]
	cmp r2, #0
	blt _080A365C
	cmp r1, #0
	blt _080A365C
	ldr r0, _080A3660 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A365C
	ldr r0, _080A3664 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A3668
_080A365C:
	movs r6, #0
	b _080A3676
	.align 2, 0
_080A3660: .4byte 0x030046A8
_080A3664: .4byte 0x030046AC
_080A3668:
	ldr r0, _080A3688 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080A3676:
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080A368C
	adds r0, #4
	b _080A3698
	.align 2, 0
_080A3688: .4byte 0x030046A4
_080A368C:
	ldr r0, _080A36AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A3698:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A36B0
	cmp r2, #2
	beq _080A36B4
	b _080A36B8
	.align 2, 0
_080A36AC: .4byte 0x030046A4
_080A36B0:
	ldrb r0, [r4, #4]
	b _080A36B6
_080A36B4:
	ldrb r0, [r4]
_080A36B6:
	subs r1, r1, r0
_080A36B8:
	strh r1, [r5]
	b _080A36CE
_080A36BC:
	adds r1, r7, #0
	adds r1, #0x98
	strh r2, [r1]
	adds r0, r7, #0
	adds r0, #0x9a
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	str r1, [sp, #0xc]
_080A36CE:
	movs r0, #0x43
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A36E8
	bl VM_GetValue
	movs r2, #0xdb
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A36F0
_080A36E8:
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A36F0:
	movs r0, #0x63
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A370A
	bl VM_GetValue
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A3712
_080A370A:
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A3712:
	movs r0, #0x69
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A372C
	bl VM_GetValue
	movs r2, #0xdc
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A3734
_080A372C:
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A3734:
	movs r0, #0x6f
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A374E
	bl VM_GetValue
	movs r2, #0xdd
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A3756
_080A374E:
	movs r3, #0xdd
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A3756:
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A376A
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x4e
	b _080A3770
_080A376A:
	adds r1, r7, #0
	adds r1, #0x4e
	movs r0, #6
_080A3770:
	strh r0, [r1]
	mov sl, r1
	movs r0, #0x61
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A3790
	bl VM_GetValue
	ldr r2, _080A378C @ =0x00000369
	adds r1, r7, r2
	strb r0, [r1]
	b _080A3796
	.align 2, 0
_080A378C: .4byte 0x00000369
_080A3790:
	ldr r3, _080A37B0 @ =0x00000369
	adds r0, r7, r3
	strb r1, [r0]
_080A3796:
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A37B4
	bl VM_GetValue
	movs r2, #0xde
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A37BC
	.align 2, 0
_080A37B0: .4byte 0x00000369
_080A37B4:
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A37BC:
	mov r1, sl
	ldrh r0, [r1]
	lsrs r0, r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, #0x61
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r6, r7, r2
	strh r1, [r6]
	movs r3, #0x7c
	adds r3, r3, r7
	mov r8, r3
	ldr r5, _080A3930 @ =0x00000BA8
	mov r0, r8
	adds r1, r5, #0
	bl Video_GetAuxSprite
	adds r4, r7, #0
	adds r4, #0x50
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl AuxSprite_Add
	mov r1, sl
	ldrh r0, [r1]
	strh r0, [r4, #0x10]
	ldrh r1, [r6]
	mov r0, r8
	bl Video_SetAuxSpritePltt
	ldr r0, [r7, #0x50]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r7, #0x50]
	adds r0, r7, #0
	adds r0, #0x57
	movs r2, #3
	mov sb, r2
	mov r3, sb
	strb r3, [r0]
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x6c]
	str r1, [r7, #0x70]
	adds r4, #0x7c
	adds r0, r4, #0
	adds r1, r5, #0
	bl Video_GetAuxSprite
	adds r5, r7, #0
	adds r5, #0xa0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r3, sl
	ldrh r0, [r3]
	strh r0, [r5, #0x10]
	ldrh r1, [r6]
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r5]
	adds r0, r7, #0
	adds r0, #0xa7
	mov r1, sb
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0xbc
	ldr r3, [sp, #0xc]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0
	mov sb, r0
	mov r1, r8
	str r1, [sp, #8]
	mov r8, r5
	adds r2, #0x2c
	str r2, [sp, #0x10]
	adds r3, r7, #0
	adds r3, #0x18
	str r3, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0x4c
	str r0, [sp, #4]
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r6, r7, r1
_080A3882:
	adds r0, r6, #0
	ldr r1, _080A3930 @ =0x00000BA8
	bl Video_GetAuxSprite
	movs r0, #0x2c
	mov r4, sb
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, #0xe8
	adds r0, r7, r0
	adds r1, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r2, sl
	ldrh r0, [r2]
	movs r5, #1
	adds r1, r5, #0
	ands r1, r0
	adds r0, r4, r7
	adds r0, #0xe8
	adds r1, #0x10
	strh r1, [r0, #0x10]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	adds r1, #2
	adds r0, r6, #0
	bl Video_SetAuxSpritePltt
	ldr r0, [sp, #0x10]
	adds r2, r0, r4
	ldr r0, [r2]
	ldr r1, _080A3934 @ =0x00000201
	orrs r0, r1
	str r0, [r2]
	adds r1, r7, r4
	adds r0, r1, #0
	adds r0, #0xef
	movs r2, #1
	strb r2, [r0]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r2, r1, r3
	ldr r3, [sp, #0xc]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r6, #0x1c
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #2
	ble _080A3882
	adds r0, r7, #0
	bl FUN_080a3568
	ldr r0, [sp, #0x14]
	ldr r1, [sp]
	movs r2, #0xa
	bl MsgQueue_Register
	movs r0, #0x44
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3940
	movs r2, #0
	movs r1, #0
	ldr r3, [sp, #4]
	strh r1, [r3]
	movs r3, #0xe3
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	ldr r3, _080A3938 @ =0x0000036A
	adds r0, r7, r3
	strh r1, [r0]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, _080A393C @ =FUN_080a2a2c
	b _080A3A70
	.align 2, 0
_080A3930: .4byte 0x00000BA8
_080A3934: .4byte 0x00000201
_080A3938: .4byte 0x0000036A
_080A393C: .4byte FUN_080a2a2c
_080A3940:
	movs r4, #0
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3952
	bl VM_GetValue
	adds r4, r0, #0
_080A3952:
	movs r6, #0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3964
	bl VM_GetValue
	adds r6, r0, #0
_080A3964:
	cmp r4, #0
	beq _080A3A24
	movs r0, #0xb0
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r5, [r0]
	movs r0, #0
	bl FUN_080a6e88
	ldr r4, _080A3A18 @ =0x03002BE0
	ldr r0, [r4]
	ldr r1, [sp, #0xc]
	bl FUN_0807a91c
	ldr r0, [r4]
	bl FUN_0807b8dc
	ldr r0, [r7, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x50]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	adds r1, #2
	ldr r0, [sp, #8]
	bl Video_SetAuxSpritePltt
	mov r1, r8
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #7
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_080a2804
	movs r3, #0xe3
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #8
	strh r0, [r1]
	ldr r0, [sp, #4]
	strh r5, [r0]
	ldr r2, _080A3A1C @ =0x0000036A
	adds r1, r7, r2
	movs r0, #0xa
	strh r0, [r1]
	movs r3, #0xda
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0x18
	strb r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r7, r1
	strb r6, [r0]
	ldr r1, _080A3A20 @ =FUN_080a31dc
	adds r0, r7, #0
	bl FUN_080a2a14
	movs r4, #0
	movs r0, #0x77
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3A02
	bl VM_GetValue
	adds r4, r0, #0
_080A3A02:
	cmp r4, #0
	beq _080A3A88
	bl FUN_08086af0
	cmp r0, #0
	beq _080A3A88
	ldr r0, [sp, #0xc]
	bl FUN_08086a4c
	b _080A3A88
	.align 2, 0
_080A3A18: .4byte 0x03002BE0
_080A3A1C: .4byte 0x0000036A
_080A3A20: .4byte FUN_080a31dc
_080A3A24:
	movs r0, #0
	ldr r2, [sp, #4]
	strh r4, [r2]
	movs r3, #0xe3
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r4, [r1]
	ldr r2, _080A3A78 @ =0x0000036A
	adds r1, r7, r2
	strh r4, [r1]
	movs r3, #0xda
	lsls r3, r3, #2
	adds r1, r7, r3
	strb r0, [r1]
	cmp r6, #0
	beq _080A3A80
	movs r0, #0xaf
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, [r7, #0x50]
	movs r1, #2
	orrs r0, r1
	str r0, [r7, #0x50]
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r7, #0
	adds r0, #0x58
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #0x4f
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	ldr r1, _080A3A7C @ =FUN_080a2d18
_080A3A70:
	adds r0, r7, #0
	bl FUN_080a2a14
	b _080A3A88
	.align 2, 0
_080A3A78: .4byte 0x0000036A
_080A3A7C: .4byte FUN_080a2d18
_080A3A80:
	ldr r1, _080A3A9C @ =FUN_080a2e20
	adds r0, r7, #0
	bl FUN_080a2a14
_080A3A88:
	movs r0, #0
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A3A9C: .4byte FUN_080a2e20

	thumb_func_start FUN_080a3aa0
FUN_080a3aa0: @ 0x080A3AA0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0xe2
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A3AE0
	ldr r1, _080A3AD8 @ =FUN_080a34d4
	ldr r2, _080A3ADC @ =FUN_080a3518
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a35fc
	cmp r0, #0
	bge _080A3AE0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A3AE2
	.align 2, 0
_080A3AD8: .4byte FUN_080a34d4
_080A3ADC: .4byte FUN_080a3518
_080A3AE0:
	adds r0, r4, #0
_080A3AE2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a3ae8
FUN_080a3ae8: @ 0x080A3AE8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A3B5C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _080A3B64
	ldr r0, _080A3B60 @ =0x03002BE0
	ldr r3, [r0]
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A3B64
	movs r1, #0x2c
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0xac
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r2, r0, r1
	cmp r2, #0
	bge _080A3B26
	rsbs r2, r2, #0
_080A3B26:
	movs r1, #0x30
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0xb0
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r0, r1
	cmp r1, #0
	bge _080A3B3A
	rsbs r1, r1, #0
_080A3B3A:
	cmp r2, #0x60
	bgt _080A3B64
	cmp r1, #0x60
	bgt _080A3B64
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x90
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080A3B64
	movs r0, #1
	b _080A3B66
	.align 2, 0
_080A3B5C: .4byte 0x030046A0
_080A3B60: .4byte 0x03002BE0
_080A3B64:
	movs r0, #0
_080A3B66:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a3b6c
FUN_080a3b6c: @ 0x080A3B6C
	adds r2, r0, #0
	movs r3, #0x88
	lsls r3, r3, #1
	adds r0, r2, r3
	str r1, [r0]
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a3b84
FUN_080a3b84: @ 0x080A3B84
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080A3BE4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A3BA6
	movs r0, #0x81
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #9
	bhi _080A3BA6
	adds r0, #1
	strh r0, [r1]
_080A3BA6:
	adds r0, r4, #0
	bl FUN_080a3ae8
	adds r5, r0, #0
	cmp r5, #0
	beq _080A3C44
	ldrb r0, [r4, #0x1a]
	cmp r0, #1
	beq _080A3BC4
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4, #0x1a]
_080A3BC4:
	adds r0, r4, #0
	adds r0, #0xfe
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #7
	bhi _080A3BD4
	adds r0, r1, #1
	strh r0, [r6]
_080A3BD4:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x16
	bhi _080A3BE8
	adds r0, #2
	b _080A3BEA
	.align 2, 0
_080A3BE4: .4byte 0x030047A4
_080A3BE8:
	movs r0, #0x18
_080A3BEA:
	strh r0, [r1]
	movs r2, #1
	ldr r0, _080A3C34 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080A3C7A
	ldr r0, _080A3C38 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080A3C7A
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #9
	bls _080A3C7A
	movs r0, #8
	strh r0, [r6]
	movs r0, #1
	bl FUN_080a6e88
	ldr r0, _080A3C3C @ =0x03002BE0
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xac
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	ldr r1, _080A3C40 @ =FUN_080a3cec
	adds r0, r4, #0
	bl FUN_080a3b6c
	b _080A3C7A
	.align 2, 0
_080A3C34: .4byte 0x03002BC0
_080A3C38: .4byte 0x030044E0
_080A3C3C: .4byte 0x03002BE0
_080A3C40: .4byte FUN_080a3cec
_080A3C44:
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	beq _080A3C52
	ldr r0, _080A3C74 @ =0x00000199
	bl PlaySound_082406e0
	strb r5, [r4, #0x1a]
_080A3C52:
	adds r0, r4, #0
	adds r0, #0xfe
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _080A3C62
	subs r0, r1, #1
	strh r0, [r6]
_080A3C62:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #2
	bls _080A3C78
	subs r0, #2
	strh r0, [r1]
	b _080A3C7A
	.align 2, 0
_080A3C74: .4byte 0x00000199
_080A3C78:
	strh r5, [r1]
_080A3C7A:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r0, [r2]
	cmp r0, #0
	bne _080A3C90
	ldr r0, [r4, #0x64]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x64]
	b _080A3CAA
_080A3C90:
	ldr r0, [r4, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0xae
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x82
	strh r0, [r1]
_080A3CAA:
	ldrh r0, [r6]
	cmp r0, #7
	bls _080A3CC2
	adds r0, r4, #0
	adds r0, #0x90
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r1, [r1]
	adds r1, #2
	bl Video_SetAuxSpritePltt
	b _080A3CE6
_080A3CC2:
	cmp r0, #0
	beq _080A3CD8
	adds r0, r4, #0
	adds r0, #0x90
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r1, [r1]
	adds r1, #1
	bl Video_SetAuxSpritePltt
	b _080A3CE6
_080A3CD8:
	adds r0, r4, #0
	adds r0, #0x90
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
_080A3CE6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a3cec
FUN_080a3cec: @ 0x080A3CEC
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #1
	bls _080A3D02
	subs r0, #2
	b _080A3D04
_080A3D02:
	movs r0, #0
_080A3D04:
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0xae
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r1, r2
	adds r2, r4, #0
	adds r2, #0x82
	strh r1, [r2]
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A3D8A
	ldr r0, _080A3D94 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A3D8A
	ldr r0, [r4, #0x64]
	ldr r1, _080A3D98 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x6b
	movs r0, #3
	strb r0, [r1]
	adds r2, #0x32
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080A3D9C @ =FUN_080a3da4
	adds r0, r4, #0
	bl FUN_080a3b6c
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A3D8A
	ldr r1, _080A3DA0 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	add r1, sp, #8
	mov r3, sp
	str r3, [r1, #4]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp]
	adds r3, #2
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r2, #0
	bl VM_ExecByID
_080A3D8A:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3D94: .4byte 0x03002BE0
_080A3D98: .4byte 0xFFFFFDFF
_080A3D9C: .4byte FUN_080a3da4
_080A3DA0: .4byte 0xFFFF0000

	thumb_func_start FUN_080a3da4
FUN_080a3da4: @ 0x080A3DA4
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a3da8
FUN_080a3da8: @ 0x080A3DA8
	push {lr}
	movs r2, #0x88
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_080a3dbc
FUN_080a3dbc: @ 0x080A3DBC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x64
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0xb4
	bl AuxSprite_Remove
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _080A3DDC
	adds r0, r4, #0
	adds r0, #0x20
	bl Mover_Unlink
_080A3DDC:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a3de4
FUN_080a3de4: @ 0x080A3DE4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	strh r1, [r7, #0x18]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r3, r0, #0
	cmp r3, #0
	beq _080A3EA4
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0xac
	strh r0, [r4]
	bl VM_GetValue
	adds r5, r7, #0
	adds r5, #0xae
	strh r0, [r5]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0xb0
	strh r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0xc]
	cmp r2, #0
	blt _080A3E44
	cmp r1, #0
	blt _080A3E44
	ldr r0, _080A3E48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A3E44
	ldr r0, _080A3E4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A3E50
_080A3E44:
	movs r6, #0
	b _080A3E5E
	.align 2, 0
_080A3E48: .4byte 0x030046A8
_080A3E4C: .4byte 0x030046AC
_080A3E50:
	ldr r0, _080A3E70 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080A3E5E:
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080A3E74
	adds r0, #4
	b _080A3E80
	.align 2, 0
_080A3E70: .4byte 0x030046A4
_080A3E74:
	ldr r0, _080A3E94 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A3E80:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A3E98
	cmp r2, #2
	beq _080A3E9C
	b _080A3EA0
	.align 2, 0
_080A3E94: .4byte 0x030046A4
_080A3E98:
	ldrb r0, [r4, #4]
	b _080A3E9E
_080A3E9C:
	ldrb r0, [r4]
_080A3E9E:
	subs r1, r1, r0
_080A3EA0:
	strh r1, [r5]
	b _080A3EB6
_080A3EA4:
	adds r1, r7, #0
	adds r1, #0xac
	strh r3, [r1]
	adds r0, r7, #0
	adds r0, #0xae
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	str r1, [sp, #0xc]
_080A3EB6:
	movs r0, #0x73
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A3ED0
	bl VM_GetValue
	movs r2, #0x84
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
	b _080A3ED8
_080A3ED0:
	movs r2, #0x84
	lsls r2, r2, #1
	adds r0, r7, r2
	str r1, [r0]
_080A3ED8:
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3F2C
	adds r0, r7, #0
	adds r0, #0xfc
	str r0, [sp, #8]
	movs r1, #0x90
	adds r1, r1, r7
	mov r8, r1
	adds r2, r7, #0
	adds r2, #0x64
	str r2, [sp, #0x18]
	subs r0, #0x91
	str r0, [sp, #0x1c]
	adds r1, r7, #0
	adds r1, #0x80
	str r1, [sp, #0x20]
	movs r2, #0xe0
	adds r2, r2, r7
	mov sl, r2
	movs r0, #0xb4
	adds r0, r0, r7
	mov sb, r0
	adds r1, #0x3b
	str r1, [sp, #0x10]
	adds r2, r7, #0
	adds r2, #0xd0
	str r2, [sp, #0x14]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r7, r0
	movs r5, #1
_080A3F1C:
	bl VM_GetValue
	strh r0, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _080A3F1C
	b _080A3F72
_080A3F2C:
	adds r1, r7, #0
	adds r1, #0xfc
	str r1, [sp, #8]
	movs r2, #0x90
	adds r2, r2, r7
	mov r8, r2
	adds r0, r7, #0
	adds r0, #0x64
	str r0, [sp, #0x18]
	subs r1, #0x91
	str r1, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x80
	str r2, [sp, #0x20]
	movs r0, #0xe0
	adds r0, r0, r7
	mov sl, r0
	movs r1, #0xb4
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0x3b
	str r2, [sp, #0x10]
	adds r0, r7, #0
	adds r0, #0xd0
	str r0, [sp, #0x14]
	movs r1, #0
	movs r5, #1
	movs r2, #0x83
	lsls r2, r2, #1
	adds r0, r7, r2
_080A3F68:
	strh r1, [r0]
	subs r0, #2
	subs r5, #1
	cmp r5, #0
	bge _080A3F68
_080A3F72:
	movs r0, #0x68
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A3F80
	bl VM_GetValue
_080A3F80:
	strb r0, [r7, #0x1b]
	ldrb r0, [r7, #0x1b]
	cmp r0, #0
	beq _080A3FA4
	adds r4, r7, #0
	adds r4, #0x20
	ldrh r1, [r7, #0x18]
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	ldr r2, [sp, #0xc]
	movs r3, #0
	bl Mover_Init
	adds r0, r4, #0
	bl FUN_08002a48
_080A3FA4:
	movs r0, #0x6a
	ldr r1, [sp, #8]
	strh r0, [r1]
	ldr r6, _080A4044 @ =0x00000BA8
	mov r0, r8
	adds r1, r6, #0
	bl Video_GetAuxSprite
	ldr r0, [sp, #0x18]
	mov r1, r8
	movs r2, #0
	bl AuxSprite_Add
	movs r5, #7
	ldr r2, [sp, #0x18]
	strh r5, [r2, #0x10]
	ldr r0, [sp, #8]
	ldrh r1, [r0]
	mov r0, r8
	bl Video_SetAuxSpritePltt
	ldr r0, [r7, #0x64]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r7, #0x64]
	movs r4, #3
	ldr r1, [sp, #0x1c]
	strb r4, [r1]
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r2, [sp, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, sl
	adds r1, r6, #0
	bl Video_GetAuxSprite
	mov r0, sb
	mov r1, sl
	movs r2, #0
	bl AuxSprite_Add
	mov r0, sb
	strh r5, [r0, #0x10]
	ldr r2, [sp, #8]
	ldrh r1, [r2]
	mov r0, sl
	bl Video_SetAuxSpritePltt
	mov r1, sb
	ldr r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	mov r2, sb
	str r0, [r2]
	ldr r0, [sp, #0x10]
	strb r4, [r0]
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r2, [sp, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _080A4048 @ =FUN_080a3b84
	adds r0, r7, #0
	bl FUN_080a3b6c
	movs r0, #0
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A4044: .4byte 0x00000BA8
_080A4048: .4byte FUN_080a3b84

	thumb_func_start FUN_080a404c
FUN_080a404c: @ 0x080A404C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x8a
	lsls r1, r1, #1
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A408C
	ldr r1, _080A4084 @ =FUN_080a3da8
	ldr r2, _080A4088 @ =FUN_080a3dbc
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a3de4
	cmp r0, #0
	bge _080A408C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A408E
	.align 2, 0
_080A4084: .4byte FUN_080a3da8
_080A4088: .4byte FUN_080a3dbc
_080A408C:
	adds r0, r4, #0
_080A408E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a4094
FUN_080a4094: @ 0x080A4094
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A40E4 @ =0x030046A0
	ldr r3, [r0]
	movs r0, #0x30
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x64
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	cmp r2, #0
	bge _080A40B0
	rsbs r2, r2, #0
_080A40B0:
	movs r1, #0x34
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0x68
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r0, r1
	cmp r1, #0
	bge _080A40C4
	rsbs r1, r1, #0
_080A40C4:
	cmp r2, #0x60
	bgt _080A40E8
	cmp r1, #0x60
	bgt _080A40E8
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x90
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080A40E8
	movs r0, #1
	b _080A40EA
	.align 2, 0
_080A40E4: .4byte 0x030046A0
_080A40E8:
	movs r0, #0
_080A40EA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a40f0
FUN_080a40f0: @ 0x080A40F0
	adds r2, r0, #0
	adds r2, #0xc8
	str r1, [r2]
	adds r0, #0xc4
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a4100
FUN_080a4100: @ 0x080A4100
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _080A4160 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A4120
	adds r1, r4, #0
	adds r1, #0xba
	ldrh r0, [r1]
	cmp r0, #9
	bhi _080A4120
	adds r0, #1
	strh r0, [r1]
_080A4120:
	adds r0, r4, #0
	bl FUN_080a4094
	adds r6, r0, #0
	cmp r6, #0
	beq _080A41CC
	ldrh r0, [r4, #0x18]
	cmp r0, #1
	beq _080A413E
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strh r0, [r4, #0x18]
_080A413E:
	adds r0, r4, #0
	adds r0, #0xb6
	ldrh r1, [r0]
	adds r7, r0, #0
	cmp r1, #7
	bhi _080A414E
	adds r0, r1, #1
	strh r0, [r7]
_080A414E:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	adds r5, r0, #0
	cmp r1, #0x16
	bhi _080A4164
	adds r0, r1, #2
	b _080A4166
	.align 2, 0
_080A4160: .4byte 0x030047A4
_080A4164:
	movs r0, #0x18
_080A4166:
	strh r0, [r5]
	movs r2, #1
	ldr r0, _080A41BC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080A4202
	ldr r0, _080A41C0 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080A4202
	ldr r6, _080A41C4 @ =0x03002BE0
	ldr r0, [r6]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A4202
	adds r0, r4, #0
	adds r0, #0xba
	ldrh r0, [r0]
	cmp r0, #9
	bls _080A4202
	movs r0, #8
	strh r0, [r7]
	movs r0, #1
	bl FUN_080a6e88
	ldr r0, [r6]
	adds r1, r4, #0
	adds r1, #0x64
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	ldr r1, _080A41C8 @ =FUN_080a4250
	adds r0, r4, #0
	bl FUN_080a40f0
	b _080A4202
	.align 2, 0
_080A41BC: .4byte 0x03002BC0
_080A41C0: .4byte 0x030044E0
_080A41C4: .4byte 0x03002BE0
_080A41C8: .4byte FUN_080a4250
_080A41CC:
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	beq _080A41DA
	ldr r0, _080A41FC @ =0x00000199
	bl PlaySound_082406e0
	strh r6, [r4, #0x18]
_080A41DA:
	adds r0, r4, #0
	adds r0, #0xb6
	ldrh r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	beq _080A41EA
	subs r0, r1, #1
	strh r0, [r7]
_080A41EA:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	adds r5, r0, #0
	cmp r1, #2
	bls _080A4200
	subs r0, r1, #2
	strh r0, [r5]
	b _080A4202
	.align 2, 0
_080A41FC: .4byte 0x00000199
_080A4200:
	strh r6, [r5]
_080A4202:
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A4212
	ldr r0, [r4, #0x1c]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x1c]
	b _080A4228
_080A4212:
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x66
	ldrh r0, [r5]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x3a]
_080A4228:
	ldrh r0, [r7]
	cmp r0, #7
	bls _080A423C
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #0x8f
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	b _080A424A
_080A423C:
	adds r0, r4, #0
	adds r0, #0x48
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
_080A424A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a4250
FUN_080a4250: @ 0x080A4250
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb8
	ldrh r0, [r1]
	cmp r0, #1
	bls _080A4264
	subs r0, #2
	b _080A4266
_080A4264:
	movs r0, #0
_080A4266:
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0x66
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r4, #0x3a]
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A42E0
	ldr r0, _080A42E8 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A42E0
	ldr r0, [r4, #0x1c]
	ldr r1, _080A42EC @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x23
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r4, #0x6c]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x6c]
	ldr r1, _080A42F0 @ =FUN_080a42f8
	adds r0, r4, #0
	bl FUN_080a40f0
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r2, [r0]
	cmp r2, #0
	beq _080A42E0
	ldr r1, _080A42F4 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	add r1, sp, #8
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0xbe
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r2, #0
	bl VM_ExecByID
_080A42E0:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A42E8: .4byte 0x03002BE0
_080A42EC: .4byte 0xFFFFFDFF
_080A42F0: .4byte FUN_080a42f8
_080A42F4: .4byte 0xFFFF0000

	thumb_func_start FUN_080a42f8
FUN_080a42f8: @ 0x080A42F8
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a42fc
FUN_080a42fc: @ 0x080A42FC
	push {lr}
	adds r1, r0, #0
	adds r1, #0xc8
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a4310
FUN_080a4310: @ 0x080A4310
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	bl AuxSprite_Remove
	adds r4, #0x6c
	adds r0, r4, #0
	bl AuxSprite_Remove
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a432c
FUN_080a432c: @ 0x080A432C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4348
	bl VM_GetValue
_080A4348:
	strb r0, [r6, #0x1a]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A43FC
	bl VM_GetValue
	adds r4, r6, #0
	adds r4, #0x64
	strh r0, [r4]
	bl VM_GetValue
	adds r5, r6, #0
	adds r5, #0x66
	strh r0, [r5]
	bl VM_GetValue
	adds r1, r6, #0
	adds r1, #0x68
	strh r0, [r1]
	adds r7, r4, #0
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A439A
	cmp r1, #0
	blt _080A439A
	ldr r0, _080A43A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A439A
	ldr r0, _080A43A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A43A8
_080A439A:
	movs r4, #0
	b _080A43B6
	.align 2, 0
_080A43A0: .4byte 0x030046A8
_080A43A4: .4byte 0x030046AC
_080A43A8:
	ldr r0, _080A43C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A43B6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080A43CC
	adds r0, #4
	b _080A43D8
	.align 2, 0
_080A43C8: .4byte 0x030046A4
_080A43CC:
	ldr r0, _080A43EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A43D8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A43F0
	cmp r2, #2
	beq _080A43F4
	b _080A43F8
	.align 2, 0
_080A43EC: .4byte 0x030046A4
_080A43F0:
	ldrb r0, [r7, #4]
	b _080A43F6
_080A43F4:
	ldrb r0, [r7]
_080A43F6:
	subs r1, r1, r0
_080A43F8:
	strh r1, [r5]
	b _080A440A
_080A43FC:
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_080A440A:
	movs r0, #0x52
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A4422
	bl VM_GetValue
	adds r1, r6, #0
	adds r1, #0xc0
	str r0, [r1]
	b _080A4428
_080A4422:
	adds r0, r6, #0
	adds r0, #0xc0
	str r1, [r0]
_080A4428:
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4474
	movs r0, #0xb4
	adds r0, r0, r6
	mov r8, r0
	adds r7, r6, #0
	adds r7, #0x48
	movs r1, #0x1c
	adds r1, r1, r6
	mov sl, r1
	adds r2, r6, #0
	adds r2, #0x23
	str r2, [sp, #0xc]
	movs r0, #0x98
	adds r0, r0, r6
	mov sb, r0
	adds r1, r6, #0
	adds r1, #0x6c
	str r1, [sp]
	adds r2, #0x50
	str r2, [sp, #4]
	adds r0, r6, #0
	adds r0, #0x88
	str r0, [sp, #8]
	adds r4, r6, #0
	adds r4, #0xbc
	movs r5, #1
_080A4464:
	bl VM_GetValue
	strh r0, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _080A4464
	b _080A44AE
_080A4474:
	movs r1, #0xb4
	adds r1, r1, r6
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0x48
	movs r2, #0x1c
	adds r2, r2, r6
	mov sl, r2
	adds r0, r6, #0
	adds r0, #0x23
	str r0, [sp, #0xc]
	movs r1, #0x98
	adds r1, r1, r6
	mov sb, r1
	adds r2, r6, #0
	adds r2, #0x6c
	str r2, [sp]
	adds r0, #0x50
	str r0, [sp, #4]
	adds r1, r6, #0
	adds r1, #0x88
	str r1, [sp, #8]
	adds r1, #0x34
	movs r2, #0
	adds r0, #0x4b
_080A44A6:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _080A44A6
_080A44AE:
	ldrb r0, [r6, #0x1a]
	cmp r0, #0
	bne _080A44BE
	movs r0, #0x8e
	lsls r0, r0, #1
	mov r2, r8
	strh r0, [r2]
	b _080A44C4
_080A44BE:
	ldr r0, _080A4548 @ =0x0000011D
	mov r1, r8
	strh r0, [r1]
_080A44C4:
	ldr r5, _080A454C @ =0x0000A152
	adds r0, r7, #0
	adds r1, r5, #0
	bl Video_GetAuxSprite
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r2, r8
	ldrh r1, [r2]
	adds r0, r7, #0
	bl Video_SetAuxSpritePltt
	ldr r0, [r6, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r6, #0x1c]
	movs r4, #3
	ldr r0, [sp, #0xc]
	strb r4, [r0]
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
	mov r0, sb
	adds r1, r5, #0
	bl Video_GetAuxSprite
	ldr r0, [sp]
	mov r1, sb
	movs r2, #0
	bl AuxSprite_Add
	mov r2, r8
	ldrh r1, [r2]
	mov r0, sb
	bl Video_SetAuxSpritePltt
	ldr r0, [r6, #0x6c]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r6, #0x6c]
	ldr r0, [sp, #4]
	strb r4, [r0]
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	ldr r2, [sp, #8]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _080A4550 @ =FUN_080a4100
	adds r0, r6, #0
	bl FUN_080a40f0
	movs r0, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A4548: .4byte 0x0000011D
_080A454C: .4byte 0x0000A152
_080A4550: .4byte FUN_080a4100

	thumb_func_start FUN_080a4554
FUN_080a4554: @ 0x080A4554
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #9
	movs r1, #0xcc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4590
	ldr r1, _080A4588 @ =FUN_080a42fc
	ldr r2, _080A458C @ =FUN_080a4310
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a432c
	cmp r0, #0
	bge _080A4590
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A4592
	.align 2, 0
_080A4588: .4byte FUN_080a42fc
_080A458C: .4byte FUN_080a4310
_080A4590:
	adds r0, r4, #0
_080A4592:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a4598
FUN_080a4598: @ 0x080A4598
	movs r3, #0x84
	lsls r3, r3, #1
	adds r2, r0, r3
	str r1, [r2]
	adds r0, #0xec
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start FUN_080a45a8
FUN_080a45a8: @ 0x080A45A8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0xe4
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A45DE
	ldr r0, [r4]
	movs r1, #4
	ands r0, r1
	movs r5, #1
	cmp r0, #0
	beq _080A45C4
	movs r5, #2
_080A45C4:
	adds r0, r4, #0
	adds r0, #0xde
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080A45D4
	asrs r0, r0, #8
	b _080A45DA
_080A45D4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A45DA:
	adds r3, r0, #1
	b _080A45F6
_080A45DE:
	movs r5, #0
	adds r0, r4, #0
	adds r0, #0xde
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080A45F0
	asrs r3, r0, #8
	b _080A45F6
_080A45F0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r3, r0, #0
_080A45F6:
	adds r0, r4, #0
	adds r0, #0xf8
	adds r1, r4, #0
	adds r1, #0xea
	ldrh r1, [r1]
	movs r2, #0xff
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	adds r2, r5, #0
	bl Map_AddTileOverride
	adds r1, r4, #0
	adds r1, #0xf7
	movs r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a4620
FUN_080a4620: @ 0x080A4620
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r2, #0
	adds r4, #0xf4
	ldrb r0, [r4]
	cmp r0, #0
	bne _080A465C
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _080A465C
	ldr r0, _080A4664 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A4668 @ =0x00000942
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0xf0
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0x20
	strb r0, [r4]
	ldr r0, _080A466C @ =0x03002C44
	ldr r1, [r0]
	movs r0, #1
	strb r0, [r1, #0x19]
_080A465C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4664: .4byte 0x030046A0
_080A4668: .4byte 0x00000942
_080A466C: .4byte 0x03002C44

	thumb_func_start FUN_080a4670
FUN_080a4670: @ 0x080A4670
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xf0
	adds r1, r4, #0
	adds r1, #0xf2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	blo _080A46A4
	adds r1, r4, #0
	adds r1, #0xf6
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080a45a8
	adds r2, r4, #0
	adds r2, #0x4e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080A46AC @ =FUN_080a46b0
	adds r0, r4, #0
	bl FUN_080a4598
_080A46A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A46AC: .4byte FUN_080a46b0

	thumb_func_start FUN_080a46b0
FUN_080a46b0: @ 0x080A46B0
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r6, #2
	strb r6, [r5, #7]
	adds r4, r5, #0
	adds r4, #0xec
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A46CC
	movs r0, #0xd5
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080A46CC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080A46E0
	movs r0, #1
	strh r0, [r5, #0x10]
	b _080A4718
_080A46E0:
	strh r6, [r5, #0x10]
	ldr r1, _080A4720 @ =FUN_080a4728
	adds r0, r5, #0
	bl FUN_080a4598
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A4718
	ldr r1, _080A4724 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r3, sp
	str r3, [r1, #4]
	adds r0, r5, #0
	adds r0, #0xe8
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	adds r0, r2, #0
	bl VM_ExecByID
_080A4718:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A4720: .4byte FUN_080a4728
_080A4724: .4byte 0xFFFF0000

	thumb_func_start FUN_080a4728
FUN_080a4728: @ 0x080A4728
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a472c
FUN_080a472c: @ 0x080A472C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r2, r5, #0
	adds r2, #0xee
	ldrh r0, [r2]
	cmp r0, #0
	beq _080A4794
	adds r4, r5, #0
	adds r4, #0xec
	ldrh r1, [r4]
	lsls r0, r1, #8
	subs r0, r0, r1
	ldrh r1, [r2]
	bl Div
	ldr r2, _080A4768 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r0, #0
	ldrsh r1, [r1, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _080A476C
	asrs r1, r0, #0xc
	b _080A4772
	.align 2, 0
_080A4768: .4byte 0x085B0A08
_080A476C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A4772:
	adds r0, r5, #0
	adds r0, #0xde
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r5, #0x1e]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	adds r1, r5, #0
	adds r1, #0xee
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080A4794
	movs r0, #0
	strh r0, [r4]
_080A4794:
	adds r0, r5, #0
	adds r0, #0xf0
	adds r1, r5, #0
	adds r1, #0xf2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	blo _080A47C6
	adds r1, r5, #0
	adds r1, #0xf6
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080a45a8
	adds r2, r5, #0
	adds r2, #0x4e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080A47CC @ =FUN_080a47d0
	adds r0, r5, #0
	bl FUN_080a4598
_080A47C6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A47CC: .4byte FUN_080a47d0

	thumb_func_start FUN_080a47d0
FUN_080a47d0: @ 0x080A47D0
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xec
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A47E8
	movs r0, #0xd5
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080A47E8:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080A4808
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r0, #1
	strh r0, [r5, #0x10]
	b _080A4842
_080A4808:
	movs r0, #2
	strh r0, [r5, #0x10]
	ldr r1, _080A484C @ =FUN_080a4854
	adds r0, r5, #0
	bl FUN_080a4598
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A4842
	ldr r1, _080A4850 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r3, sp
	str r3, [r1, #4]
	adds r0, r5, #0
	adds r0, #0xe8
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	adds r0, r2, #0
	bl VM_ExecByID
_080A4842:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A484C: .4byte FUN_080a4854
_080A4850: .4byte 0xFFFF0000

	thumb_func_start FUN_080a4854
FUN_080a4854: @ 0x080A4854
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A4898 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xea
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080A48A0
	adds r5, r4, #0
	adds r5, #0xde
	movs r2, #0x1e
	ldrsh r1, [r4, r2]
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bne _080A4884
	ldr r0, _080A489C @ =0x000002B3
	bl PlaySound_082406e0
_080A4884:
	movs r0, #0x1e
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	subs r0, #0x10
	cmp r1, r0
	ble _080A48B6
	ldrh r0, [r4, #0x1e]
	subs r0, #2
	b _080A48B4
	.align 2, 0
_080A4898: .4byte 0x03002BE0
_080A489C: .4byte 0x000002B3
_080A48A0:
	adds r0, r4, #0
	adds r0, #0xde
	ldrh r2, [r4, #0x1e]
	movs r3, #0x1e
	ldrsh r1, [r4, r3]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _080A48B6
	adds r0, r2, #2
_080A48B4:
	strh r0, [r4, #0x1e]
_080A48B6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a48bc
FUN_080a48bc: @ 0x080A48BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _080A48DE
	ldr r0, _080A48FC @ =0x000001A9
	bl PlaySound_082406e0
	movs r1, #0
	movs r0, #0x20
	strb r0, [r4, #0x1b]
	strb r1, [r4, #0x19]
_080A48DE:
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _080A49BC
	subs r0, #1
	strb r0, [r4, #0x1b]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080A4904
	ldr r0, _080A4900 @ =0x03003584
	ldr r0, [r0]
	movs r1, #0xbe
	lsls r1, r1, #4
	adds r0, r0, r1
	b _080A4912
	.align 2, 0
_080A48FC: .4byte 0x000001A9
_080A4900: .4byte 0x03003584
_080A4904:
	cmp r0, #0xf
	bls _080A4928
	ldr r0, _080A4920 @ =0x03003584
	ldr r0, [r0]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r0, r0, r2
_080A4912:
	adds r1, r4, #0
	adds r1, #0x1c
	ldr r2, _080A4924 @ =0x04000008
	bl CpuSet
	b _080A49BC
	.align 2, 0
_080A4920: .4byte 0x03003584
_080A4924: .4byte 0x04000008
_080A4928:
	ldrb r7, [r4, #0x1b]
	movs r0, #0x10
	subs r0, r0, r7
	str r0, [sp]
	ldr r0, _080A49CC @ =0x03003584
	ldr r0, [r0]
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r3, r3, r0
	mov sl, r3
	movs r5, #0xbe
	lsls r5, r5, #4
	adds r5, r5, r0
	mov r8, r5
	movs r6, #0
	mov sb, r6
	adds r4, #0x1c
	str r4, [sp, #4]
	movs r0, #0x1f
	mov ip, r0
_080A4950:
	mov r1, sl
	ldrh r3, [r1]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	mov r5, ip
	ands r6, r5
	lsrs r3, r3, #0x1a
	ands r3, r5
	mov r0, r8
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x15
	ands r4, r5
	lsrs r1, r1, #0x1a
	ands r1, r5
	adds r5, r2, #0
	muls r5, r7, r5
	ldr r2, [sp]
	muls r0, r2, r0
	adds r5, r5, r0
	asrs r5, r5, #4
	adds r2, r6, #0
	muls r2, r7, r2
	ldr r6, [sp]
	adds r0, r4, #0
	muls r0, r6, r0
	adds r2, r2, r0
	asrs r2, r2, #4
	adds r0, r3, #0
	muls r0, r7, r0
	muls r1, r6, r1
	adds r0, r0, r1
	asrs r0, r0, #4
	mov r3, sb
	lsls r1, r3, #1
	ldr r6, [sp, #4]
	adds r1, r6, r1
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	strh r0, [r1]
	movs r0, #2
	add sl, r0
	add r8, r0
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #0xf
	ble _080A4950
_080A49BC:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A49CC: .4byte 0x03003584

	thumb_func_start FUN_080a49d0
FUN_080a49d0: @ 0x080A49D0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	bl FUN_080a48bc
	movs r0, #0
	mov r8, r0
	ldrb r0, [r6, #0x18]
	cmp r8, r0
	bge _080A4A34
	adds r5, r6, #0
	adds r5, #0x68
	movs r0, #0x98
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r7, r6, #0
	adds r7, #0x3c
_080A49F4:
	ldr r1, [r4, #0x14]
	adds r0, r7, #0
	bl _call_via_r1
	ldrb r0, [r4]
	cmp r0, #0
	beq _080A4A20
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A4A18
	movs r0, #0x60
	strh r0, [r5, #6]
	adds r0, r6, #0
	adds r0, #0x1c
	str r0, [r5, #0xc]
	b _080A4A20
_080A4A18:
	adds r0, r5, #0
	movs r1, #0x5f
	bl Video_SetAuxSpritePltt
_080A4A20:
	movs r0, #0x88
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r7, r7, r0
	movs r0, #1
	add r8, r0
	ldrb r0, [r6, #0x18]
	cmp r8, r0
	blt _080A49F4
_080A4A34:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a4a40
FUN_080a4a40: @ 0x080A4A40
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0
	mov sl, r0
	ldrb r0, [r5, #0x18]
	cmp sl, r0
	bge _080A4AAC
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r0, r5
	mov sb, r0
	movs r0, #0x84
	adds r0, r0, r5
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0xd4
	ldr r0, _080A4AC0 @ =0x00000121
	adds r4, r5, r0
	adds r6, r5, #0
	adds r6, #0x3c
_080A4A70:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080A4A7C
	adds r0, r7, #0
	bl Mover_Unlink
_080A4A7C:
	adds r0, r6, #0
	bl AuxSprite_Remove
	mov r0, r8
	bl Hitbox_Unregister
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A4A94
	mov r0, sb
	bl Map_RemoveTileOverride
_080A4A94:
	movs r0, #0x88
	lsls r0, r0, #1
	add sb, r0
	add r8, r0
	adds r7, r7, r0
	adds r4, r4, r0
	adds r6, r6, r0
	movs r0, #1
	add sl, r0
	ldrb r0, [r5, #0x18]
	cmp sl, r0
	blt _080A4A70
_080A4AAC:
	ldr r1, _080A4AC4 @ =0x03002C44
	movs r0, #0
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A4AC0: .4byte 0x00000121
_080A4AC4: .4byte 0x03002C44

	thumb_func_start FUN_080a4ac8
FUN_080a4ac8: @ 0x080A4AC8
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x48
	ldr r2, _080A4B3C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _080A4B40 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	adds r0, r4, #0
	adds r0, #0xe6
	ldrh r1, [r0]
	ldr r2, _080A4B44 @ =0x00004002
	movs r0, #0x20
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _080A4B48 @ =0x080A4621
	adds r0, r5, #0
	adds r2, r4, #0
	bl Hitbox_SetHandler
	adds r4, #0xdc
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A4B3C: .4byte 0xFFFF0000
_080A4B40: .4byte 0x0000FFFF
_080A4B44: .4byte 0x00004002
_080A4B48: .4byte 0x080A4621

	thumb_func_start FUN_080a4b4c
FUN_080a4b4c: @ 0x080A4B4C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	ldrb r1, [r0, #0x18]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, #0x3c
	mov r1, sb
	adds r5, r1, r0
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A4B82
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xe6
	strh r0, [r1]
	mov sl, r1
	b _080A4B8A
_080A4B82:
	adds r0, r5, #0
	adds r0, #0xe6
	strh r1, [r0]
	mov sl, r0
_080A4B8A:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4BB8
	bl VM_GetValue
	adds r4, r5, #0
	adds r4, #0xdc
	strh r0, [r4]
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xde
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xe0
	strh r0, [r1]
	adds r6, r4, #0
	b _080A4BCA
_080A4BB8:
	adds r1, r5, #0
	adds r1, #0xdc
	strh r2, [r1]
	adds r0, r5, #0
	adds r0, #0xde
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r6, r1, #0
_080A4BCA:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A4BEE
	cmp r1, #0
	blt _080A4BEE
	ldr r0, _080A4BF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A4BEE
	ldr r0, _080A4BF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A4BFC
_080A4BEE:
	movs r0, #0
	b _080A4C0A
	.align 2, 0
_080A4BF4: .4byte 0x030046A8
_080A4BF8: .4byte 0x030046AC
_080A4BFC:
	ldr r0, _080A4C24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A4C0A:
	adds r2, r5, #0
	adds r2, #0xea
	strh r0, [r2]
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4C28
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xe4
	b _080A4C2E
	.align 2, 0
_080A4C24: .4byte 0x030046A4
_080A4C28:
	adds r1, r5, #0
	adds r1, #0xe4
	movs r0, #0
_080A4C2E:
	strb r0, [r1]
	mov r8, r1
	mov r2, r8
	ldrb r0, [r2]
	ldr r1, _080A4CB8 @ =0x0000D166
	cmp r0, #0
	bne _080A4C3E
	ldr r1, _080A4CBC @ =0x0000C3C3
_080A4C3E:
	adds r7, r5, #0
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #3
	strb r0, [r5, #7]
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4C72
	bl VM_GetValue
	cmp r0, #0
	beq _080A4C72
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080A4C72:
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	movs r0, #0x68
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4CC0
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xe5
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A4CC6
	adds r4, r5, #0
	adds r4, #0x98
	mov r0, sl
	ldrh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Mover_Init
	adds r0, r4, #0
	bl FUN_08002a48
	b _080A4CC6
	.align 2, 0
_080A4CB8: .4byte 0x0000D166
_080A4CBC: .4byte 0x0000C3C3
_080A4CC0:
	adds r1, r5, #0
	adds r1, #0xe5
	strb r0, [r1]
_080A4CC6:
	adds r0, r5, #0
	adds r0, #0xf0
	movs r1, #0
	strh r1, [r0]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4CE2
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xf2
	b _080A4CE8
_080A4CE2:
	adds r1, r5, #0
	adds r1, #0xf2
	movs r0, #0xa
_080A4CE8:
	strh r0, [r1]
	movs r0, #0x57
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4CF8
	bl VM_GetValue
_080A4CF8:
	adds r1, r5, #0
	adds r1, #0xee
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080a4ac8
	adds r1, r5, #0
	adds r1, #0xf4
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x73
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A4D26
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xf6
	strb r0, [r1]
	adds r0, r1, #0
	b _080A4D2C
_080A4D26:
	adds r0, r5, #0
	adds r0, #0xf6
	strb r1, [r0]
_080A4D2C:
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A4D64
	adds r0, r5, #0
	bl FUN_080a45a8
	adds r2, r5, #0
	adds r2, #0x4e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r0, #2
	strh r0, [r7, #0x10]
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne _080A4D5C
	movs r0, #2
	strb r0, [r7, #7]
	ldr r1, _080A4D58 @ =0x080A4729
	b _080A4D7A
	.align 2, 0
_080A4D58: .4byte 0x080A4729
_080A4D5C:
	ldr r1, _080A4D60 @ =FUN_080a4854
	b _080A4D7A
	.align 2, 0
_080A4D60: .4byte FUN_080a4854
_080A4D64:
	adds r1, r5, #0
	adds r1, #0xf7
	strb r0, [r1]
	strh r0, [r7, #0x10]
	movs r0, #3
	strb r0, [r7, #7]
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne _080A4D88
	ldr r1, _080A4D84 @ =FUN_080a4670
_080A4D7A:
	adds r0, r5, #0
	bl FUN_080a4598
	b _080A4D90
	.align 2, 0
_080A4D84: .4byte FUN_080a4670
_080A4D88:
	ldr r1, _080A4DB4 @ =FUN_080a472c
	adds r0, r5, #0
	bl FUN_080a4598
_080A4D90:
	movs r0, #0x67
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4DB8
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xe8
	strh r0, [r1]
	bl VM_GetValue
	movs r2, #0x86
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	b _080A4DC8
	.align 2, 0
_080A4DB4: .4byte FUN_080a472c
_080A4DB8:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, _080A4DE0 @ =0x0000FFFF
	strh r1, [r0]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	str r2, [r0]
_080A4DC8:
	mov r2, sb
	ldrb r0, [r2, #0x18]
	adds r0, #1
	strb r0, [r2, #0x18]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A4DE0: .4byte 0x0000FFFF

	thumb_func_start FUN_080a4de4
FUN_080a4de4: @ 0x080A4DE4
	push {r4, lr}
	ldr r1, _080A4E0C @ =0x000008BC
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4E00
	ldr r1, _080A4E10 @ =FUN_080a49d0
	ldr r2, _080A4E14 @ =FUN_080a4a40
	bl SetEntityRoutine
	movs r0, #0
	strb r0, [r4, #0x18]
_080A4E00:
	ldr r0, _080A4E18 @ =0x03002C44
	str r4, [r0]
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A4E0C: .4byte 0x000008BC
_080A4E10: .4byte FUN_080a49d0
_080A4E14: .4byte FUN_080a4a40
_080A4E18: .4byte 0x03002C44

	thumb_func_start FUN_080a4e1c
FUN_080a4e1c: @ 0x080A4E1C
	push {r4, r5, r6, r7, lr}
	ldr r0, _080A4E38 @ =0x03002C44
	ldr r4, [r0]
	cmp r4, #0
	beq _080A4E70
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4E46
	bl VM_GetValue
	adds r5, r0, #0
	b _080A4E48
	.align 2, 0
_080A4E38: .4byte 0x03002C44
_080A4E3C:
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	b _080A4E72
_080A4E46:
	movs r5, #0
_080A4E48:
	movs r3, #0
	ldrb r0, [r4, #0x18]
	cmp r3, r0
	bge _080A4E70
	adds r6, r0, #0
	movs r7, #0x92
	lsls r7, r7, #1
	adds r1, r4, r7
	adds r2, r4, #0
	movs r4, #0x88
	lsls r4, r4, #1
_080A4E5E:
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r5
	beq _080A4E3C
	adds r1, r1, r4
	adds r2, r2, r4
	adds r3, #1
	cmp r3, r6
	blt _080A4E5E
_080A4E70:
	movs r0, #0
_080A4E72:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a4e78
FUN_080a4e78: @ 0x080A4E78
	push {lr}
	ldr r0, _080A4E90 @ =0x03002C44
	ldr r0, [r0]
	cmp r0, #0
	bne _080A4E86
	bl FUN_080a4de4
_080A4E86:
	bl FUN_080a4b4c
	pop {r1}
	bx r1
	.align 2, 0
_080A4E90: .4byte 0x03002C44

	thumb_func_start FUN_080a4e94
FUN_080a4e94: @ 0x080A4E94
	push {r4, r5, r6, lr}
	ldr r4, _080A4EAC @ =0x03002C48
	ldr r0, [r4]
	cmp r0, #0
	beq _080A4EE0
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _080A4EB8
	b _080A4EE0
	.align 2, 0
_080A4EAC: .4byte 0x03002C48
_080A4EB0:
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r5, r0
	b _080A4EE2
_080A4EB8:
	bl VM_GetValue
	adds r6, r0, #0
	movs r2, #0
	ldr r0, [r4]
	ldrb r1, [r0, #0x19]
	cmp r2, r1
	bge _080A4EE0
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r5, #0
	movs r3, #0
_080A4ED0:
	ldrh r0, [r1, #0x1c]
	cmp r0, r6
	beq _080A4EB0
	adds r1, #0xb8
	adds r3, #0xb8
	adds r2, #1
	cmp r2, r4
	blt _080A4ED0
_080A4EE0:
	movs r0, #0
_080A4EE2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a4ee8
FUN_080a4ee8: @ 0x080A4EE8
	push {r4, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4F4E
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4F4E
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x78
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x7a
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x7c
	strh r0, [r1]
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4F4E
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x80
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A4F4E
	ldrb r1, [r4, #2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #2]
	ldr r0, [r4, #0x44]
	ldr r1, [r4, #0x48]
	str r0, [r4, #0x70]
	str r1, [r4, #0x74]
	adds r1, r4, #0
	adds r1, #0x82
	movs r0, #0
	strh r0, [r1]
_080A4F4E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a4f54
FUN_080a4f54: @ 0x080A4F54
	push {r4, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4F70
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4F70
	bl VM_GetValue
	strh r0, [r4, #0x38]
_080A4F70:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a4f78
FUN_080a4f78: @ 0x080A4F78
	push {lr}
	bl FUN_080a4e94
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4F8C
	ldr r0, [r2, #0x28]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x28]
_080A4F8C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a4f90
FUN_080a4f90: @ 0x080A4F90
	push {lr}
	bl FUN_080a4e94
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4FA6
	ldr r0, [r2, #0x28]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x28]
_080A4FA6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a4fac
FUN_080a4fac: @ 0x080A4FAC
	push {r4, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4FCC
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4FCC
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x2f
	strb r0, [r1]
_080A4FCC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a4fd4
FUN_080a4fd4: @ 0x080A4FD4
	push {r4, r5, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5046
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5046
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x86
	strh r0, [r1]
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5046
	bl VM_GetValue
	adds r5, r4, #0
	adds r5, #0x88
	strh r0, [r5]
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5046
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x8c
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _080A5036
	adds r0, r4, #0
	adds r0, #0x54
	subs r1, #8
	ldrh r1, [r1]
	ldrh r2, [r5]
	adds r1, r1, r2
	bl Video_SetAuxSpritePltt
	b _080A5046
_080A5036:
	adds r1, r4, #0
	adds r1, #0x8a
	movs r0, #0
	strh r0, [r1]
	ldrb r1, [r4, #2]
	movs r0, #2
	orrs r0, r1
	strb r0, [r4, #2]
_080A5046:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a504c
FUN_080a504c: @ 0x080A504C
	push {r4, r5, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A50D2
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A50D2
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x90
	strh r0, [r1]
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A50D2
	bl VM_GetValue
	adds r5, r4, #0
	adds r5, #0x92
	strh r0, [r5]
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A50D2
	bl VM_GetValue
	adds r2, r4, #0
	adds r2, #0x96
	strh r0, [r2]
	ldrh r0, [r5]
	adds r3, r4, #0
	adds r3, #0x30
	strb r0, [r3]
	adds r1, r4, #0
	adds r1, #0x31
	strb r0, [r1]
	ldrh r0, [r2]
	cmp r0, #1
	bhi _080A50BA
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0x40
	beq _080A50D2
	ldr r0, [r4, #0x28]
	movs r1, #2
	orrs r0, r1
	str r0, [r4, #0x28]
	b _080A50D2
_080A50BA:
	ldr r0, [r4, #0x28]
	movs r1, #2
	orrs r0, r1
	str r0, [r4, #0x28]
	adds r1, r4, #0
	adds r1, #0x94
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r4, #2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r4, #2]
_080A50D2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a50d8
FUN_080a50d8: @ 0x080A50D8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	bl FUN_080a4e94
	adds r5, r0, #0
	cmp r5, #0
	beq _080A51CC
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A51CC
	bl VM_GetValue
	adds r7, r5, #0
	adds r7, #0x98
	strb r0, [r7]
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A51CC
	bl VM_GetValue
	adds r6, r5, #0
	adds r6, #0x99
	strb r0, [r6]
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A51CC
	bl VM_GetValue
	strb r0, [r5, #3]
	movs r4, #0
	movs r0, #0x45
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5130
	bl VM_GetValue
	adds r4, r0, #0
_080A5130:
	cmp r4, #0
	beq _080A514E
	adds r4, r5, #0
	adds r4, #0x9c
	adds r0, r5, #0
	adds r0, #0xac
	ldr r1, [r0]
	ldrb r2, [r7]
	ldrb r3, [r6]
	ldrb r0, [r5, #3]
	str r0, [sp]
	adds r0, r4, #0
	bl AuxAnim_RestartAnim
	b _080A5166
_080A514E:
	adds r4, r5, #0
	adds r4, #0x9c
	adds r0, r5, #0
	adds r0, #0xac
	ldr r1, [r0]
	ldrb r2, [r7]
	ldrb r3, [r6]
	ldrb r0, [r5, #3]
	str r0, [sp]
	adds r0, r4, #0
	bl AuxAnim_SetAnim
_080A5166:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5180
	bl VM_GetValue
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
_080A5180:
	movs r0, #0x6f
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A519A
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0x9a
	strb r0, [r1]
	adds r0, r1, #0
	b _080A51A0
_080A519A:
	adds r0, r5, #0
	adds r0, #0x9a
	strb r1, [r0]
_080A51A0:
	ldrb r1, [r0]
	cmp r1, #0
	beq _080A51BE
	movs r0, #0x65
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A51BE
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xb0
	str r0, [r1]
	b _080A51C4
_080A51BE:
	adds r0, r5, #0
	adds r0, #0xb0
	str r1, [r0]
_080A51C4:
	ldrb r1, [r5, #2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r5, #2]
_080A51CC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a51d4
FUN_080a51d4: @ 0x080A51D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldrb r1, [r7, #2]
	cmp r1, #0
	bne _080A51EA
	b _080A5556
_080A51EA:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080A5284
	adds r6, r7, #0
	adds r6, #0x82
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	adds r5, r7, #0
	adds r5, #0x80
	ldrh r1, [r5]
	ldrh r3, [r6]
	subs r4, r1, r3
	adds r0, r7, #0
	adds r0, #0x70
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r2, r0, #0
	muls r2, r4, r2
	mov r8, r2
	adds r2, r7, #0
	adds r2, #0x78
	movs r0, #0
	ldrsh r2, [r2, r0]
	muls r2, r3, r2
	mov r3, r8
	adds r0, r3, r2
	bl Div
	adds r1, r7, #0
	adds r1, #0x44
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x72
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	adds r1, r7, #0
	adds r1, #0x7a
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldrh r1, [r6]
	muls r1, r2, r1
	adds r0, r0, r1
	ldrh r1, [r5]
	bl Div
	adds r1, r7, #0
	adds r1, #0x46
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	adds r1, r7, #0
	adds r1, #0x7c
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldrh r1, [r6]
	muls r1, r2, r1
	adds r0, r0, r1
	ldrh r1, [r5]
	bl Div
	adds r1, r7, #0
	adds r1, #0x48
	strh r0, [r1]
	ldrh r0, [r6]
	ldrh r5, [r5]
	cmp r0, r5
	blo _080A5284
	ldrb r1, [r7, #2]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #2]
_080A5284:
	ldrb r1, [r7, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080A5290
	b _080A53B6
_080A5290:
	adds r3, r7, #0
	adds r3, #0x8a
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	adds r4, r7, #0
	adds r4, #0x8c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4]
	cmp r0, r1
	blo _080A52C8
	adds r0, r7, #0
	adds r0, #0x54
	adds r1, r7, #0
	adds r1, #0x84
	ldrh r1, [r1]
	adds r2, r7, #0
	adds r2, #0x88
	ldrh r2, [r2]
	adds r1, r1, r2
	bl Video_SetAuxSpritePltt
	ldrb r1, [r7, #2]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r7, #2]
	b _080A53B6
_080A52C8:
	ldr r2, _080A5408 @ =0x03003584
	adds r0, r7, #0
	adds r0, #0x84
	ldrh r1, [r0]
	adds r0, #2
	ldrh r0, [r0]
	adds r0, r1, r0
	lsls r0, r0, #5
	ldr r2, [r2]
	adds r0, r2, r0
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r0, #0x88
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r2, r1
	str r2, [sp, #8]
	ldrh r1, [r4]
	ldrh r0, [r3]
	subs r1, r1, r0
	str r1, [sp, #0xc]
	adds r2, r7, #0
	adds r2, #8
	str r2, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0x5a
	str r0, [sp, #0x18]
	str r3, [sp, #0x10]
	mov sb, r4
	mov sl, r2
	movs r1, #0xf
	str r1, [sp]
_080A530A:
	ldr r2, [sp, #4]
	ldrh r5, [r2]
	movs r0, #0x1f
	ands r0, r5
	lsls r5, r5, #0x10
	lsrs r3, r5, #0x15
	movs r1, #0x1f
	ands r3, r1
	lsrs r5, r5, #0x1a
	ands r5, r1
	ldr r2, [sp, #8]
	ldrh r4, [r2]
	movs r2, #0x1f
	ands r2, r4
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x15
	ands r6, r1
	lsrs r4, r4, #0x1a
	ands r4, r1
	ldr r1, [sp, #0xc]
	muls r0, r1, r0
	ldr r1, [sp, #0x10]
	ldrh r1, [r1]
	mov r8, r1
	mov r1, r8
	muls r1, r2, r1
	adds r0, r0, r1
	mov r2, sb
	ldrh r1, [r2]
	str r3, [sp, #0x1c]
	bl Div
	mov r8, r0
	ldr r3, [sp, #0x1c]
	ldr r1, [sp, #0xc]
	adds r0, r3, #0
	muls r0, r1, r0
	ldr r2, [sp, #0x10]
	ldrh r1, [r2]
	muls r1, r6, r1
	adds r0, r0, r1
	mov r3, sb
	ldrh r1, [r3]
	bl Div
	adds r6, r0, #0
	ldr r1, [sp, #0xc]
	adds r0, r5, #0
	muls r0, r1, r0
	ldr r2, [sp, #0x10]
	ldrh r1, [r2]
	muls r1, r4, r1
	adds r0, r0, r1
	mov r3, sb
	ldrh r1, [r3]
	bl Div
	lsls r0, r0, #0xa
	lsls r6, r6, #5
	orrs r0, r6
	mov r1, r8
	orrs r0, r1
	mov r2, sl
	strh r0, [r2]
	ldr r3, [sp, #4]
	adds r3, #2
	str r3, [sp, #4]
	ldr r0, [sp, #8]
	adds r0, #2
	str r0, [sp, #8]
	movs r1, #2
	add sl, r1
	ldr r2, [sp]
	subs r2, #1
	str r2, [sp]
	cmp r2, #0
	bge _080A530A
	ldr r3, [sp, #0x14]
	str r3, [r7, #0x60]
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r1, #0
	ldrh r2, [r7]
	adds r0, r0, r2
	ldr r3, [sp, #0x18]
	strh r0, [r3]
_080A53B6:
	ldrb r1, [r7, #2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080A543A
	adds r3, r7, #0
	adds r3, #0x94
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	adds r4, r7, #0
	adds r4, #0x96
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4]
	cmp r0, r1
	blo _080A540C
	adds r0, r7, #0
	adds r0, #0x92
	ldrh r0, [r0]
	adds r1, r7, #0
	adds r1, #0x30
	strb r0, [r1]
	adds r2, r7, #0
	adds r2, #0x31
	strb r0, [r2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x40
	bne _080A53FC
	ldr r0, [r7, #0x28]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x28]
_080A53FC:
	ldrb r1, [r7, #2]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #2]
	b _080A543A
	.align 2, 0
_080A5408: .4byte 0x03003584
_080A540C:
	ldr r0, [r7, #0x28]
	movs r1, #2
	orrs r0, r1
	str r0, [r7, #0x28]
	adds r0, r7, #0
	adds r0, #0x90
	ldrh r2, [r0]
	ldrh r1, [r4]
	ldrh r3, [r3]
	subs r0, r1, r3
	muls r0, r2, r0
	adds r2, r7, #0
	adds r2, #0x92
	ldrh r2, [r2]
	muls r2, r3, r2
	adds r0, r0, r2
	bl Div
	adds r1, r7, #0
	adds r1, #0x30
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
_080A543A:
	ldrb r1, [r7, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080A5446
	b _080A5556
_080A5446:
	adds r6, r7, #0
	adds r6, #0x28
	adds r4, r7, #0
	adds r4, #0x9c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
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
	beq _080A547A
	ldr r0, [r7, #0x28]
	movs r1, #4
	orrs r0, r1
	b _080A5482
_080A547A:
	ldr r0, [r7, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080A5482:
	str r0, [r7, #0x28]
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
	beq _080A54A6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080A54AE
_080A54A6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080A54AE:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080A54E8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080A552E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080A54F2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080A54EC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080A5508
	.align 2, 0
_080A54E8: .4byte 0x0000FFFF
_080A54EC:
	subs r0, #1
	strh r0, [r4, #8]
	b _080A5506
_080A54F2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080A5506
	strh r1, [r4, #8]
	movs r2, #1
	b _080A5508
_080A5506:
	movs r2, #0
_080A5508:
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
	bne _080A5530
	movs r0, #1
	strb r0, [r4, #7]
	b _080A5530
_080A552E:
	movs r2, #0
_080A5530:
	cmp r2, #0
	beq _080A5556
	adds r0, r7, #0
	adds r0, #0x9a
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A5556
	ldrb r0, [r7, #2]
	movs r1, #0xf7
	ands r1, r0
	strb r1, [r7, #2]
	adds r0, r7, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0
	beq _080A5556
	movs r1, #0
	bl VM_ExecByID
_080A5556:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5568
FUN_080a5568: @ 0x080A5568
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r0, _080A55D0 @ =0x03002C48
	ldr r4, [r0]
	cmp r4, #0
	bne _080A557C
	b _080A583C
_080A557C:
	ldrb r0, [r4, #0x19]
	ldrb r1, [r4, #0x18]
	cmp r0, r1
	blo _080A5586
	b _080A583C
_080A5586:
	adds r1, r0, #0
	movs r0, #0xb8
	muls r0, r1, r0
	adds r0, #0x1c
	adds r7, r4, r0
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A559E
	bl VM_GetValue
_080A559E:
	strh r0, [r7]
	adds r4, r7, #0
	adds r4, #0x28
	adds r5, r7, #0
	adds r5, #0x54
	movs r0, #0x74
	bl VM_SeekToNamedArg
	mov sb, r4
	cmp r0, #0
	bne _080A55B6
	b _080A583C
_080A55B6:
	bl VM_GetValue
	mov r8, r0
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A55D4
	bl VM_GetValue
	adds r6, r0, #0
	b _080A55D6
	.align 2, 0
_080A55D0: .4byte 0x03002C48
_080A55D4:
	movs r6, #0
_080A55D6:
	adds r0, r5, #0
	mov r1, r8
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r2, #0
	strh r6, [r4, #0x10]
	ldrh r1, [r5, #6]
	adds r0, r7, #0
	adds r0, #0x84
	strh r1, [r0]
	strb r2, [r7, #3]
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5606
	bl VM_GetValue
	strb r0, [r7, #3]
_080A5606:
	ldrb r0, [r7, #3]
	cmp r0, #0
	beq _080A5614
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	str r0, [r4]
_080A5614:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5630
	bl VM_GetValue
	strh r0, [r4, #0x1c]
	bl VM_GetValue
	strh r0, [r4, #0x1e]
	bl VM_GetValue
	b _080A5634
_080A5630:
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
_080A5634:
	strh r0, [r4, #0x20]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5644
	bl VM_GetValue
_080A5644:
	strb r0, [r7, #4]
	movs r0, #0x52
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5656
	bl VM_GetValue
	strb r0, [r4, #7]
_080A5656:
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	bne _080A5664
	b _080A57E6
_080A5664:
	ldr r4, _080A56B0 @ =0x0000922E
	bl VM_GetValue
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl GetFile
	adds r6, r7, #0
	adds r6, #0xac
	str r0, [r6]
	bl VM_GetValue
	adds r5, r7, #0
	adds r5, #0x98
	strb r0, [r5]
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0x99
	strb r0, [r4]
	movs r0, #0x6f
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	mov r8, r6
	adds r6, r4, #0
	cmp r1, #0
	beq _080A56B4
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x9a
	strb r0, [r1]
	adds r0, r1, #0
	b _080A56BA
	.align 2, 0
_080A56B0: .4byte 0x0000922E
_080A56B4:
	adds r0, r7, #0
	adds r0, #0x9a
	strb r1, [r0]
_080A56BA:
	ldrb r1, [r0]
	cmp r1, #0
	beq _080A56D8
	movs r0, #0x65
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A56D8
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0xb0
	str r0, [r1]
	b _080A56DE
_080A56D8:
	adds r0, r7, #0
	adds r0, #0xb0
	str r1, [r0]
_080A56DE:
	adds r4, r7, #0
	adds r4, #0x9c
	mov r2, r8
	ldr r1, [r2]
	ldrb r2, [r5]
	ldrb r3, [r6]
	ldrb r0, [r7, #3]
	str r0, [sp]
	adds r0, r4, #0
	bl AuxAnim_SetAnim
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A570E
	bl VM_GetValue
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
_080A570E:
	mov r6, sb
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
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
	beq _080A573C
	ldr r0, [r7, #0x28]
	movs r1, #4
	orrs r0, r1
	b _080A5744
_080A573C:
	ldr r0, [r7, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080A5744:
	str r0, [r7, #0x28]
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
	beq _080A5768
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080A5770
_080A5768:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080A5770:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080A57A8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080A57E0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080A57AC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080A57A0
	ldrb r0, [r4, #5]
_080A57A0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080A57BC
	.align 2, 0
_080A57A8: .4byte 0x0000FFFF
_080A57AC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080A57BC
	strh r1, [r4, #8]
_080A57BC:
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
	bne _080A57E0
	movs r0, #1
	strb r0, [r4, #7]
_080A57E0:
	movs r0, #8
	strb r0, [r7, #2]
	b _080A57F6
_080A57E6:
	adds r0, r7, #0
	adds r0, #0xac
	str r1, [r0]
	subs r0, #0x12
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	strb r1, [r7, #2]
_080A57F6:
	movs r5, #0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5808
	bl VM_GetValue
	adds r5, r0, #0
_080A5808:
	adds r4, r7, #0
	adds r4, #0xb4
	movs r0, #0
	str r0, [r4]
	cmp r5, #0
	beq _080A5832
	movs r0, #0x40
	bl Malloc
	str r0, [r4]
	cmp r0, #0
	beq _080A5832
	movs r1, #0x40
	bl ClearMemory
	ldr r0, [r4]
	adds r1, r7, #0
	adds r1, #0x44
	movs r2, #0
	bl ParticleShadow_Init
_080A5832:
	ldr r0, _080A584C @ =0x03002C48
	ldr r1, [r0]
	ldrb r0, [r1, #0x19]
	adds r0, #1
	strb r0, [r1, #0x19]
_080A583C:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A584C: .4byte 0x03002C48

	thumb_func_start FUN_080a5850
FUN_080a5850: @ 0x080A5850
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	bge _080A587E
	adds r4, r6, #0
	adds r4, #0x1c
_080A5860:
	ldr r0, _080A5888 @ =0x030044BC
	ldr r0, [r0]
	cmp r0, #0
	beq _080A586E
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _080A5874
_080A586E:
	adds r0, r4, #0
	bl FUN_080a51d4
_080A5874:
	adds r4, #0xb8
	adds r5, #1
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	blt _080A5860
_080A587E:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A5888: .4byte 0x030044BC

	thumb_func_start FUN_080a588c
FUN_080a588c: @ 0x080A588C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	b _080A58BA
_080A5894:
	movs r0, #0xb8
	adds r4, r6, #0
	muls r4, r0, r4
	adds r0, r4, r5
	adds r0, #0x44
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0xd0
	adds r4, r0, r4
	ldr r0, [r4]
	cmp r0, #0
	beq _080A58B8
	bl ParticleShadow_Remove
	ldr r0, [r4]
	bl Free
_080A58B8:
	adds r6, #1
_080A58BA:
	ldrb r0, [r5, #0x19]
	cmp r6, r0
	blt _080A5894
	ldr r1, _080A58CC @ =0x03002C48
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A58CC: .4byte 0x03002C48

	thumb_func_start FUN_080a58d0
FUN_080a58d0: @ 0x080A58D0
	movs r1, #0
	strb r3, [r0, #0x18]
	strb r1, [r0, #0x19]
	ldr r1, _080A58E0 @ =0x03002C48
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_080A58E0: .4byte 0x03002C48

	thumb_func_start FUN_080a58e4
FUN_080a58e4: @ 0x080A58E4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _080A5904 @ =0x03002C48
	ldr r0, [r0]
	cmp r0, #0
	bne _080A594A
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5908
	bl VM_GetValue
	adds r5, r0, #0
	b _080A590A
	.align 2, 0
_080A5904: .4byte 0x03002C48
_080A5908:
	movs r5, #1
_080A590A:
	movs r0, #0xb8
	adds r1, r5, #0
	muls r1, r0, r1
	adds r1, #0x1c
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5948
	ldr r1, _080A5940 @ =FUN_080a5850
	ldr r2, _080A5944 @ =FUN_080a588c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	adds r3, r5, #0
	bl FUN_080a58d0
	cmp r0, #0
	bge _080A5948
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A594A
	.align 2, 0
_080A5940: .4byte FUN_080a5850
_080A5944: .4byte FUN_080a588c
_080A5948:
	adds r0, r4, #0
_080A594A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a5950
FUN_080a5950: @ 0x080A5950
	push {r4, r5, r6, lr}
	ldr r4, _080A5968 @ =0x03002C4C
	ldr r0, [r4]
	cmp r0, #0
	beq _080A599E
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _080A5974
	b _080A599E
	.align 2, 0
_080A5968: .4byte 0x03002C4C
_080A596C:
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r5, r0
	b _080A59A0
_080A5974:
	bl VM_GetValue
	adds r6, r0, #0
	movs r2, #0
	ldr r0, [r4]
	ldrb r1, [r0, #0x19]
	cmp r2, r1
	bge _080A599E
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r5, #0
	adds r1, #0xb4
	movs r3, #0
_080A598E:
	ldrh r0, [r1]
	cmp r0, r6
	beq _080A596C
	adds r1, #0xbc
	adds r3, #0xbc
	adds r2, #1
	cmp r2, r4
	blt _080A598E
_080A599E:
	movs r0, #0
_080A59A0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a59a8
FUN_080a59a8: @ 0x080A59A8
	push {r4, r5, lr}
	bl FUN_080a5950
	adds r5, r0, #0
	cmp r5, #0
	beq _080A59D8
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A59D8
	adds r4, r5, #0
	adds r4, #0x38
	adds r5, #0x18
	bl VM_GetValue
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0
	bl MainSprite_SetPose
_080A59D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a59e0
FUN_080a59e0: @ 0x080A59E0
	push {r4, lr}
	bl FUN_080a5950
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5A10
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5A10
	bl VM_GetValue
	cmp r0, #0
	beq _080A5A06
	ldr r0, [r4, #0x40]
	movs r1, #4
	orrs r0, r1
	b _080A5A0E
_080A5A06:
	ldr r0, [r4, #0x40]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080A5A0E:
	str r0, [r4, #0x40]
_080A5A10:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5a18
FUN_080a5a18: @ 0x080A5A18
	push {lr}
	bl FUN_080a5950
	adds r1, r0, #0
	cmp r1, #0
	beq _080A5A3C
	ldr r0, [r1, #0x40]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #0x40]
	adds r0, r1, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A5A3C
	adds r0, r1, #0
	adds r0, #0x9e
	strh r2, [r0]
_080A5A3C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5a40
FUN_080a5a40: @ 0x080A5A40
	push {lr}
	bl FUN_080a5950
	adds r2, r0, #0
	cmp r2, #0
	beq _080A5A68
	ldr r0, [r2, #0x40]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x40]
	adds r0, r2, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A5A68
	adds r1, r2, #0
	adds r1, #0x9e
	movs r0, #0
	strh r0, [r1]
_080A5A68:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5a6c
FUN_080a5a6c: @ 0x080A5A6C
	push {r4, lr}
	bl FUN_080a5950
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5A8C
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5A8C
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x52
	strb r0, [r1]
_080A5A8C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5a94
FUN_080a5a94: @ 0x080A5A94
	push {r4, lr}
	bl FUN_080a5950
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5AFA
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5AC8
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0xb4
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0xb6
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0xb8
	strh r0, [r1]
_080A5AC8:
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5ADC
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0xa2
	strh r0, [r1]
_080A5ADC:
	adds r2, r4, #0
	adds r2, #0xac
	adds r0, r4, #0
	adds r0, #0xa4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r4, #0
	adds r1, #0xa0
	movs r0, #0
	strh r0, [r1]
	subs r1, #6
	movs r0, #1
	strh r0, [r1]
_080A5AFA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5b00
FUN_080a5b00: @ 0x080A5B00
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r3, r6, #0
	adds r3, #0x9a
	ldrh r0, [r3]
	cmp r0, #0
	beq _080A5BC0
	adds r7, r6, #0
	adds r7, #0xa0
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	movs r1, #0xa2
	adds r1, r1, r6
	mov r8, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r1]
	cmp r0, r2
	blo _080A5B42
	adds r2, r6, #0
	adds r2, #0xa4
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0
	strh r0, [r3]
	b _080A5BB8
_080A5B42:
	mov r3, r8
	ldrh r1, [r3]
	ldrh r2, [r7]
	subs r4, r1, r2
	adds r0, r6, #0
	adds r0, #0xb4
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0xac
	movs r3, #0
	ldrsh r2, [r2, r3]
	muls r2, r4, r2
	adds r0, r0, r2
	bl Div
	adds r5, r6, #0
	adds r5, #0xa4
	strh r0, [r5]
	adds r0, r6, #0
	adds r0, #0xb6
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r7]
	muls r0, r1, r0
	adds r1, r6, #0
	adds r1, #0xae
	movs r3, #0
	ldrsh r1, [r1, r3]
	muls r1, r4, r1
	adds r0, r0, r1
	mov r2, r8
	ldrh r1, [r2]
	bl Div
	adds r1, r6, #0
	adds r1, #0xa6
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrh r0, [r7]
	muls r0, r1, r0
	adds r1, r6, #0
	adds r1, #0xb0
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r1, r4, r1
	adds r0, r0, r1
	mov r3, r8
	ldrh r1, [r3]
	bl Div
	adds r1, r6, #0
	adds r1, #0xa8
	strh r0, [r1]
	adds r2, r5, #0
_080A5BB8:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x58]
	str r1, [r6, #0x5c]
_080A5BC0:
	adds r0, r6, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A5BF8
	adds r0, r6, #0
	adds r0, #0x9e
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A5BF0
	ldr r0, _080A5BEC @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x14
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080A5BF0
	ldr r0, [r6, #0x40]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _080A5BF6
	.align 2, 0
_080A5BEC: .4byte 0x030046A0
_080A5BF0:
	ldr r0, [r6, #0x40]
	movs r1, #1
	orrs r0, r1
_080A5BF6:
	str r0, [r6, #0x40]
_080A5BF8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5c04
FUN_080a5c04: @ 0x080A5C04
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	ldr r0, _080A5C44 @ =0x03002C4C
	ldr r2, [r0]
	cmp r2, #0
	bne _080A5C18
	b _080A5D62
_080A5C18:
	ldrb r0, [r2, #0x19]
	ldrb r1, [r2, #0x18]
	cmp r0, r1
	blo _080A5C22
	b _080A5D62
_080A5C22:
	adds r1, r0, #0
	movs r0, #0xbc
	muls r0, r1, r0
	adds r0, #0x1c
	adds r5, r2, r0
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A5C48
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	b _080A5C4E
	.align 2, 0
_080A5C44: .4byte 0x03002C4C
_080A5C48:
	adds r0, r5, #0
	adds r0, #0x98
	strh r1, [r0]
_080A5C4E:
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _080A5C5A
	b _080A5D62
_080A5C5A:
	bl VM_GetValue
	adds r1, r0, #0
	ldr r0, _080A5C9C @ =0x0000CB05
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	adds r1, r0, #0
	adds r2, r5, #0
	adds r2, #0x18
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r4, #0
	bl OpenMainSpriteFile
	movs r0, #0x69
	bl VM_SeekToNamedArg
	mov r8, r4
	cmp r0, #0
	beq _080A5CA0
	bl VM_GetValue
	adds r7, r0, #0
	b _080A5CA2
	.align 2, 0
_080A5C9C: .4byte 0x0000CB05
_080A5CA0:
	movs r7, #0
_080A5CA2:
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5CB2
	bl VM_GetValue
	b _080A5CB4
_080A5CB2:
	movs r0, #0
_080A5CB4:
	movs r6, #0
	mov sb, r6
	cmp r0, #1
	bne _080A5CC0
	movs r0, #0x10
	mov sb, r0
_080A5CC0:
	movs r0, #0x52
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5CD2
	bl VM_GetValue
	adds r6, r0, #0
	b _080A5CD4
_080A5CD2:
	movs r6, #2
_080A5CD4:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A5D00
	bl VM_GetValue
	adds r4, r5, #0
	adds r4, #0xa4
	strh r0, [r4]
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xa6
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xa8
	strh r0, [r1]
	b _080A5D12
_080A5D00:
	adds r1, r5, #0
	adds r1, #0xa4
	strh r2, [r1]
	adds r0, r5, #0
	adds r0, #0xa6
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r4, r1, #0
_080A5D12:
	adds r0, r5, #0
	adds r0, #0x38
	lsls r2, r7, #0x10
	lsrs r2, r2, #0x10
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	mov r1, r8
	mov r3, sb
	bl MainSprite_Add
	movs r0, #0x41
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A5D4A
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	b _080A5D50
_080A5D4A:
	adds r0, r5, #0
	adds r0, #0x9c
	strh r1, [r0]
_080A5D50:
	adds r1, r5, #0
	adds r1, #0x9e
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080A5D70 @ =0x03002C4C
	ldr r1, [r0]
	ldrb r0, [r1, #0x19]
	adds r0, #1
	strb r0, [r1, #0x19]
_080A5D62:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A5D70: .4byte 0x03002C4C

	thumb_func_start Entity8AF6_Update
Entity8AF6_Update: @ 0x080A5D74
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	bge _080A5D94
	adds r4, r6, #0
	adds r4, #0x1c
_080A5D84:
	adds r0, r4, #0
	bl FUN_080a5b00
	adds r4, #0xbc
	adds r5, #1
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	blt _080A5D84
_080A5D94:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity8AF6_Destroy
Entity8AF6_Destroy: @ 0x080A5D9C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	bge _080A5DBC
	adds r4, r6, #0
	adds r4, #0x54
_080A5DAC:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0xbc
	adds r5, #1
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	blt _080A5DAC
_080A5DBC:
	ldr r1, _080A5DC8 @ =0x03002C4C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A5DC8: .4byte 0x03002C4C

	thumb_func_start Entity8AF6_Init
Entity8AF6_Init: @ 0x080A5DCC
	movs r1, #0
	strb r3, [r0, #0x18]
	strb r1, [r0, #0x19]
	ldr r1, _080A5DDC @ =0x03002C4C
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_080A5DDC: .4byte 0x03002C4C

	thumb_func_start Entity8AF6_Create
Entity8AF6_Create: @ 0x080A5DE0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _080A5E00 @ =0x03002C4C
	ldr r0, [r0]
	cmp r0, #0
	bne _080A5E46
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5E04
	bl VM_GetValue
	adds r5, r0, #0
	b _080A5E06
	.align 2, 0
_080A5E00: .4byte 0x03002C4C
_080A5E04:
	movs r5, #1
_080A5E06:
	movs r0, #0xbc
	adds r1, r5, #0
	muls r1, r0, r1
	adds r1, #0x1c
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5E44
	ldr r1, _080A5E3C @ =Entity8AF6_Update
	ldr r2, _080A5E40 @ =Entity8AF6_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	adds r3, r5, #0
	bl Entity8AF6_Init
	cmp r0, #0
	bge _080A5E44
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A5E46
	.align 2, 0
_080A5E3C: .4byte Entity8AF6_Update
_080A5E40: .4byte Entity8AF6_Destroy
_080A5E44:
	adds r0, r4, #0
_080A5E46:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a5e4c
FUN_080a5e4c: @ 0x080A5E4C
	push {lr}
	ldr r0, _080A5E64 @ =0x0300014C
	ldr r0, [r0]
	cmp r0, #0
	beq _080A5E5E
	adds r1, r0, #0
	adds r1, #0x9c
	movs r0, #1
	str r0, [r1]
_080A5E5E:
	pop {r0}
	bx r0
	.align 2, 0
_080A5E64: .4byte 0x0300014C

	thumb_func_start FUN_080a5e68
FUN_080a5e68: @ 0x080A5E68
	adds r2, r0, #0
	adds r2, #0xac
	str r1, [r2]
	adds r0, #0x9a
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a5e78
FUN_080a5e78: @ 0x080A5E78
	push {lr}
	adds r1, r0, #0
	adds r0, #0xa0
	ldr r2, [r0]
	cmp r2, #0
	beq _080A5E8C
	adds r0, #4
	ldr r0, [r0]
	bl _call_via_r2
_080A5E8C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5e90
FUN_080a5e90: @ 0x080A5E90
	push {lr}
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, #0
	beq _080A5EA0
	movs r1, #0
	bl VM_ExecByID
_080A5EA0:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5ea4
FUN_080a5ea4: @ 0x080A5EA4
	push {lr}
	adds r1, r0, #0
	adds r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A5EB8
	adds r0, r1, #0
	bl FUN_080a5e78
	b _080A5EBE
_080A5EB8:
	adds r0, r1, #0
	bl FUN_080a5e90
_080A5EBE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5ec4
FUN_080a5ec4: @ 0x080A5EC4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A5ED6
	ldr r0, _080A5F38 @ =0x000002C2
	bl PlaySound_082406e0
_080A5ED6:
	adds r0, r4, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _080A5EF8
	adds r0, r4, #0
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A5EF8
	movs r0, #0x87
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080A5EF8:
	adds r1, r4, #0
	adds r1, #0x9a
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r5, r4, #0
	adds r5, #0x38
	adds r6, r4, #0
	adds r6, #0x18
	adds r0, r5, #0
	adds r1, r6, #0
	bl MainSprite_AdvanceAnim
	cmp r0, #0
	beq _080A5F30
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x24
	movs r3, #1
	bl MainSprite_SetPose
	ldr r1, _080A5F3C @ =FUN_080a5f40
	adds r0, r4, #0
	bl FUN_080a5e68
	adds r0, r4, #0
	bl FUN_080a5ea4
_080A5F30:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A5F38: .4byte 0x000002C2
_080A5F3C: .4byte FUN_080a5f40

	thumb_func_start FUN_080a5f40
FUN_080a5f40: @ 0x080A5F40
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x9a
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A5F54
	ldr r0, _080A5F90 @ =0x000002C3
	bl PlaySound_082406e0
_080A5F54:
	ldrh r0, [r4]
	cmp r0, #7
	bhi _080A5FA0
	ldr r6, _080A5F94 @ =0x0203B400
	ldr r5, _080A5F98 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _080A5F9C @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r4, #3
	ands r0, r4
	subs r0, #2
	adds r2, r7, #0
	adds r2, #0x58
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #2
	adds r1, r7, #0
	adds r1, #0x5a
	strh r0, [r1]
	b _080A5FB0
	.align 2, 0
_080A5F90: .4byte 0x000002C3
_080A5F94: .4byte 0x0203B400
_080A5F98: .4byte 0x030046B8
_080A5F9C: .4byte 0x000003FF
_080A5FA0:
	cmp r0, #8
	bne _080A5FB0
	adds r0, r7, #0
	adds r0, #0x58
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_080A5FB0:
	adds r1, r7, #0
	adds r1, #0x9a
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _080A5FC8
	adds r0, r7, #0
	bl KillEntity
_080A5FC8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5fd0
FUN_080a5fd0: @ 0x080A5FD0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x9a
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A5FE6
	movs r0, #0xa5
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080A5FE6:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080A6000
	adds r0, r5, #0
	bl FUN_080a5ea4
	adds r0, r5, #0
	bl KillEntity
_080A6000:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EntityCF58_Update
EntityCF58_Update: @ 0x080A6008
	push {lr}
	adds r2, r0, #0
	adds r0, #0x9c
	ldr r0, [r0]
	cmp r0, #0
	beq _080A601C
	adds r0, r2, #0
	bl KillEntity
	b _080A6028
_080A601C:
	adds r0, r2, #0
	adds r0, #0xac
	ldr r1, [r0]
	adds r0, r2, #0
	bl _call_via_r1
_080A6028:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityCF58_Destroy
EntityCF58_Destroy: @ 0x080A6030
	push {lr}
	adds r0, #0x38
	bl MainSprite_Remove
	ldr r1, _080A6044 @ =0x0300014C
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_080A6044: .4byte 0x0300014C

	thumb_func_start FUN_080a6048
FUN_080a6048: @ 0x080A6048
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080A60B4 @ =0x0000CB05
	ldr r1, _080A60B8 @ =0x0000DCC1
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _080A6108
	adds r1, r4, #0
	adds r1, #0x18
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	adds r7, r4, #0
	adds r7, #0x18
	adds r0, r7, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080A60BC @ =0xFFFF0000
	movs r6, #0
	str r6, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	cmp r5, #0
	bne _080A60C0
	adds r4, #0x38
	str r5, [sp]
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0x20
	movs r3, #0x30
	bl MainSprite_Add
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	movs r3, #2
	bl MainSprite_SetAnim
	b _080A6108
	.align 2, 0
_080A60B4: .4byte 0x0000CB05
_080A60B8: .4byte 0x0000DCC1
_080A60BC: .4byte 0xFFFF0000
_080A60C0:
	cmp r5, #1
	bne _080A60E0
	adds r0, r4, #0
	adds r0, #0x38
	str r6, [sp]
	str r6, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r7, #0
	movs r2, #0x25
	movs r3, #0x30
	bl MainSprite_Add
	b _080A6108
_080A60E0:
	adds r4, #0x38
	str r6, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0x20
	movs r3, #0x30
	bl MainSprite_Add
	str r6, [sp]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	movs r3, #2
	bl MainSprite_SetAnim
_080A6108:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a6110
FUN_080a6110: @ 0x080A6110
	push {lr}
	cmp r1, #0
	bne _080A6124
	ldr r1, _080A6120 @ =0x080A5EC5
	bl FUN_080a5e68
	b _080A613A
	.align 2, 0
_080A6120: .4byte 0x080A5EC5
_080A6124:
	cmp r1, #1
	bne _080A6134
	ldr r1, _080A6130 @ =0x080A5FD1
	bl FUN_080a5e68
	b _080A613A
	.align 2, 0
_080A6130: .4byte 0x080A5FD1
_080A6134:
	ldr r1, _080A6140 @ =0x080A5EC5
	bl FUN_080a5e68
_080A613A:
	pop {r0}
	bx r0
	.align 2, 0
_080A6140: .4byte 0x080A5EC5

	thumb_func_start FUN_080a6144
FUN_080a6144: @ 0x080A6144
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r5, [sp, #0x10]
	adds r1, r4, #0
	adds r1, #0x98
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xa0
	str r3, [r0]
	adds r0, #4
	str r5, [r0]
	subs r0, #0xb
	strb r2, [r0]
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080a6048
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080a6110
	ldr r1, _080A617C @ =0x0300014C
	str r4, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A617C: .4byte 0x0300014C

	thumb_func_start FUN_080a6180
FUN_080a6180: @ 0x080A6180
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	ldr r0, _080A61CC @ =0x0300014C
	ldr r0, [r0]
	cmp r0, #0
	bne _080A61DA
	movs r0, #4
	movs r1, #0xb0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A61D8
	ldr r1, _080A61D0 @ =EntityCF58_Update
	ldr r2, _080A61D4 @ =EntityCF58_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_080a6144
	cmp r0, #0
	bge _080A61D8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A61DA
	.align 2, 0
_080A61CC: .4byte 0x0300014C
_080A61D0: .4byte EntityCF58_Update
_080A61D4: .4byte EntityCF58_Destroy
_080A61D8:
	adds r0, r4, #0
_080A61DA:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityCF58_Init
EntityCF58_Init: @ 0x080A61E8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x98
	movs r1, #1
	strb r1, [r0]
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A6204
	bl VM_GetValue
	adds r5, r0, #0
	b _080A6206
_080A6204:
	movs r5, #0
_080A6206:
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A6214
	bl VM_GetValue
_080A6214:
	adds r1, r4, #0
	adds r1, #0x99
	strb r0, [r1]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A6232
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0xa8
	str r0, [r1]
	b _080A6238
_080A6232:
	adds r0, r4, #0
	adds r0, #0xa8
	str r1, [r0]
_080A6238:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a6048
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a6110
	ldr r1, _080A6254 @ =0x0300014C
	str r4, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A6254: .4byte 0x0300014C

	thumb_func_start EntityCF58_Create
EntityCF58_Create: @ 0x080A6258
	push {r4, lr}
	ldr r0, _080A628C @ =0x0300014C
	ldr r0, [r0]
	cmp r0, #0
	bne _080A629A
	movs r0, #4
	movs r1, #0xb0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A6298
	ldr r1, _080A6290 @ =EntityCF58_Update
	ldr r2, _080A6294 @ =0x080A6031
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityCF58_Init
	cmp r0, #0
	bge _080A6298
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A629A
	.align 2, 0
_080A628C: .4byte 0x0300014C
_080A6290: .4byte 0x080A6009
_080A6294: .4byte 0x080A6031
_080A6298:
	adds r0, r4, #0
_080A629A:
	pop {r4}
	pop {r1}
	bx r1

