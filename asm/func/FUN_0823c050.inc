	push {r4, r5, lr}
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _0823C09A
	bl Script_GetValue
	adds r5, r0, #0
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0823C074
	bl Script_GetValue
	adds r4, r0, #0
	b _0823C076
_0823C074:
	movs r4, #1
_0823C076:
	movs r0, #0x4e
	bl prepare_08231510
	cmp r0, #0
	beq _0823C088
	bl Script_GetValue
	adds r2, r0, #0
	b _0823C08A
_0823C088:
	movs r2, #0
_0823C08A:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823bd14
	ldr r0, _0823C0A0 @ =gCamera
	ldr r0, [r0]
	bl FUN_0823bd98
_0823C09A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823C0A0: .4byte gCamera
