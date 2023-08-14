	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_082423a8
FUN_082423a8: @ 0x082423A8
	push {r4, lr}
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	bne _082423B8
	movs r0, #0
	b _082423D8
_082423B8:
	bl fetch_082316e4
	adds r4, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _082423D0
	bl fetch_082316e4
	adds r1, r0, #0
	b _082423D2
_082423D0:
	movs r1, #0
_082423D2:
	adds r0, r4, #0
	bl TryAddItem
_082423D8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start removeSpecifiedItem
removeSpecifiedItem: @ 0x082423E0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_082423E6:
	adds r0, r4, #0
	bl GetNormalItemID
	cmp r0, r5
	bne _082423FA
	adds r0, r4, #0
	bl RemoveItem
	movs r0, #1
	b _08242402
_082423FA:
	adds r4, #1
	cmp r4, #0xf
	ble _082423E6
	movs r0, #0
_08242402:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start removeSpecifiedValuable
removeSpecifiedValuable: @ 0x08242408
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_0824240E:
	adds r0, r4, #0
	bl GetValuableItemID
	cmp r0, r5
	bne _08242422
	adds r0, r4, #0
	bl RemoveValuable
	movs r0, #1
	b _0824242A
_08242422:
	adds r4, #1
	cmp r4, #0xf
	ble _0824240E
	movs r0, #0
_0824242A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start RemoveSpecifiedItem
RemoveSpecifiedItem: @ 0x08242430
	push {r4, lr}
	adds r4, r0, #0
	bl IsValuable
	cmp r0, #0
	beq _08242444
	adds r0, r4, #0
	bl removeSpecifiedValuable
	b _0824244A
_08242444:
	adds r0, r4, #0
	bl removeSpecifiedItem
_0824244A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08242450
FUN_08242450: @ 0x08242450
	push {lr}
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	bne _08242460
	movs r0, #0
	b _08242468
_08242460:
	bl fetch_082316e4
	bl RemoveSpecifiedItem
_08242468:
	pop {r1}
	bx r1
