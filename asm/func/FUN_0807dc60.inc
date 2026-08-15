	push {r4, r5, r6, lr}
	bl FUN_0807afe8
	ldr r1, _0807DC9C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r6, [r0]
	cmp r6, #0
	beq _0807DCC6
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _0807DCC6
	bl Script_GetValue
	adds r5, r0, #0
	subs r0, r5, #4
	cmp r0, #1
	bhi _0807DCB8
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _0807DCA0
	bl Script_GetValue
	adds r4, r0, #0
	b _0807DCA2
	.align 2, 0
_0807DC9C: .4byte 0x03002BE0
_0807DCA0:
	movs r4, #0x78
_0807DCA2:
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _0807DCB4
	bl Script_GetValue
	adds r3, r0, #0
	b _0807DCBC
_0807DCB4:
	movs r3, #0x78
	b _0807DCBC
_0807DCB8:
	movs r3, #0
	movs r4, #0
_0807DCBC:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0807cec4
_0807DCC6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
