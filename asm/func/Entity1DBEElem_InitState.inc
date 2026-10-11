	push {lr}
	adds r1, r0, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809FE3C
	strh r0, [r1, #0x10]
	ldr r2, _0809FE38 @ =FUN_0809fabc
	adds r0, r1, #0
	movs r1, #0
	bl Entity1DBEElem_SetState
	b _0809FE66
	.align 2, 0
_0809FE38: .4byte FUN_0809fabc
_0809FE3C:
	cmp r0, #2
	bne _0809FE54
	movs r0, #8
	strh r0, [r1, #0x10]
	ldr r2, _0809FE50 @ =FUN_0809f8e4
	adds r0, r1, #0
	movs r1, #2
	bl Entity1DBEElem_SetState
	b _0809FE66
	.align 2, 0
_0809FE50: .4byte FUN_0809f8e4
_0809FE54:
	cmp r0, #1
	bne _0809FE66
	movs r0, #5
	strh r0, [r1, #0x10]
	ldr r2, _0809FE6C @ =FUN_0809f7fc
	adds r0, r1, #0
	movs r1, #1
	bl Entity1DBEElem_SetState
_0809FE66:
	pop {r0}
	bx r0
	.align 2, 0
_0809FE6C: .4byte FUN_0809f7fc
