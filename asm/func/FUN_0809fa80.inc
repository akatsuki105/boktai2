	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xee
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0809FA9C
	movs r0, #7
	strh r0, [r3, #0x10]
	b _0809FAB4
_0809FA9C:
	cmp r0, #0xf
	bhi _0809FAA6
	movs r0, #6
	strh r0, [r3, #0x10]
	b _0809FAB4
_0809FAA6:
	movs r0, #2
	strh r0, [r3, #0x10]
	ldr r2, _0809FAB8 @ =FUN_0809fabc
	adds r0, r3, #0
	movs r1, #0
	bl Entity1DBEElem_SetState
_0809FAB4:
	pop {r0}
	bx r0
	.align 2, 0
_0809FAB8: .4byte FUN_0809fabc
