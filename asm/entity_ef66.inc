	.include "asm/macros.inc"

	.syntax unified
	
	.text

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

	thumb_func_start EntityEF66_Update
EntityEF66_Update: @ 0x080A1304
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

	thumb_func_start EntityEF66_Destroy
EntityEF66_Destroy: @ 0x080A1478
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

	thumb_func_start EntityEF66_Init
EntityEF66_Init: @ 0x080A14A0
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

	thumb_func_start EntityEF66_Create
EntityEF66_Create: @ 0x080A1664
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
	ldr r1, _080A16A0 @ =EntityEF66_Update
	ldr r2, _080A16A4 @ =EntityEF66_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityEF66_Init
	cmp r0, #0
	bge _080A16A8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A16AA
	.align 2, 0
_080A169C: .4byte 0x03000148
_080A16A0: .4byte EntityEF66_Update
_080A16A4: .4byte EntityEF66_Destroy
_080A16A8:
	adds r0, r4, #0
_080A16AA:
	pop {r4, r5}
	pop {r1}
	bx r1
