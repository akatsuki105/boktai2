	push {r4, lr}
	ldr r0, _08240FAC @ =0x03001700
	ldr r4, [r0]
	cmp r4, #0
	beq _08240FD4
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _08240FD4
	b _08240FCC
	.align 2, 0
_08240FAC: .4byte 0x03001700
_08240FB0:
	bl fetch_082316e4
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08240f20
	cmp r0, #0
	blt _08240FCC
	lsls r0, r0, #2
	adds r1, r4, #0
	adds r1, #0x98
	adds r1, r1, r0
	movs r0, #0
	str r0, [r1]
_08240FCC:
	bl FUN_082316bc
	cmp r0, #0
	bne _08240FB0
_08240FD4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
