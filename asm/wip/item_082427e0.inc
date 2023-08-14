	push {r4, lr}
	movs r4, #0
_082427E4:
	adds r0, r4, #0
	movs r1, #1
	rsbs r1, r1, #0
	bl SetItem
	adds r0, r4, #0
	movs r1, #0
	bl SetRotCount
	adds r0, r4, #0
	bl UncoverChocolate
	adds r4, #1
	cmp r4, #0x2f
	ble _082427E4
	movs r4, #0
_08242804:
	adds r0, r4, #0
	movs r1, #1
	rsbs r1, r1, #0
	bl SetValuable
	adds r4, #1
	cmp r4, #0xf
	ble _08242804
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08242826
	bl fetch_082316e4
	adds r4, r0, #0
	b _08242828
_08242826:
	movs r4, #0
_08242828:
	cmp r4, #0
	ble _0824284A
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _0824284A
	cmp r4, #0
	ble _0824284A
_0824283A:
	bl fetch_082316e4
	movs r1, #0
	bl TryAddItem
	subs r4, #1
	cmp r4, #0
	bne _0824283A
_0824284A:
	pop {r4}
	pop {r0}
	bx r0
