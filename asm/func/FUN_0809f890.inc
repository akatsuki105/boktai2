	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xee
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809F8A6
	movs r0, #0xd0
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0809F8A6:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0809F8BA
	movs r0, #4
	strh r0, [r5, #0x10]
	b _0809F8DA
_0809F8BA:
	cmp r0, #0xf
	bhi _0809F8C4
	movs r0, #3
	strh r0, [r5, #0x10]
	b _0809F8DA
_0809F8C4:
	movs r0, #2
	strh r0, [r5, #0x10]
	movs r0, #0xd0
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r2, _0809F8E0 @ =FUN_0809fabc
	adds r0, r5, #0
	movs r1, #0
	bl Entity1DBEElem_SetState
_0809F8DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809F8E0: .4byte FUN_0809fabc
