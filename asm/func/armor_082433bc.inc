	push {r4, r5, lr}
	movs r4, #0
	ldr r5, _08243408 @ =0x030046A0
	movs r3, #0xe8
	lsls r3, r3, #2
	movs r2, #0
_082433C8:
	ldr r1, [r5]
	lsls r0, r4, #2
	adds r0, r0, r1
	adds r0, r0, r3
	str r2, [r0]
	adds r4, #1
	cmp r4, #1
	ble _082433C8
	movs r4, #0
_082433DA:
	adds r0, r4, #0
	bl RemoveArmorFromInventory
	adds r4, #1
	cmp r4, #0x1f
	ble _082433DA
	ldr r0, _08243408 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	strh r1, [r0]
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _0824340C
	bl fetch_082316e4
	adds r5, r0, #0
	b _0824340E
	.align 2, 0
_08243408: .4byte 0x030046A0
_0824340C:
	movs r5, #0
_0824340E:
	cmp r5, #0
	ble _0824344A
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _08243434
	movs r4, #0
	cmp r4, r5
	bge _08243434
_08243422:
	bl fetch_082316e4
	adds r1, r0, #0
	adds r0, r4, #0
	bl SetArmorIntoInventory
	adds r4, #1
	cmp r4, r5
	blt _08243422
_08243434:
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _0824344A
	bl fetch_082316e4
	ldr r1, _08243450 @ =0x030046A0
	ldr r1, [r1]
	adds r1, #0x5c
	strh r0, [r1]
_0824344A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08243450: .4byte 0x030046A0
