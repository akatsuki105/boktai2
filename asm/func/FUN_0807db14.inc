	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807DB38 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807DB52
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _0807DB3C
	bl Script_GetValue
	adds r4, r0, #0
	b _0807DB3E
	.align 2, 0
_0807DB38: .4byte 0x03002BE0
_0807DB3C:
	movs r4, #0
_0807DB3E:
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807ca24
	adds r0, r5, #0
	bl FUN_08072640
_0807DB52:
	pop {r4, r5}
	pop {r0}
	bx r0
