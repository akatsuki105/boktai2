	push {r4, r5, r6, lr}
	ldr r5, _080916B8 @ =0x03002C10
	movs r0, #0
	strh r0, [r5]
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080916B2
	movs r4, #0
	movs r6, #1
_0809169A:
	bl Script_GetValue
	cmp r0, #0
	beq _080916AC
	adds r0, r6, #0
	lsls r0, r4
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_080916AC:
	adds r4, #1
	cmp r4, #3
	ble _0809169A
_080916B2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080916B8: .4byte 0x03002C10
