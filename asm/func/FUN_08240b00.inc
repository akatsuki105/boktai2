	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08240B10 @ =0x03001700
	ldr r0, [r0]
	cmp r0, #0
	bne _08240B18
	b _08240B3C
	.align 2, 0
_08240B10: .4byte 0x03001700
_08240B14:
	movs r0, #1
	b _08240B3E
_08240B18:
	movs r5, #0
	adds r4, r0, #0
	adds r4, #0x98
_08240B1E:
	ldr r0, [r4]
	cmp r0, #0
	ble _08240B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	bl FUN_08234d50
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08240B14
_08240B34:
	adds r4, #4
	adds r5, #1
	cmp r5, #0xf
	ble _08240B1E
_08240B3C:
	movs r0, #0
_08240B3E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
