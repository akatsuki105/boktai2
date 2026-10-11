	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [r5, #0x50]
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081E22EA
	bl FUN_0823d340
	str r0, [r5, #0x54]
	cmp r0, #0
	bne _081E22EA
	adds r0, r4, #0
	b _081E2322
_081E22EA:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r5, #0
	adds r1, #0x6e
	movs r4, #0
	strh r0, [r1]
	adds r0, r5, #0
	bl LinkShopManager_SetupBG
	adds r0, r5, #0
	bl LinkShopManager_OpenTextBox
	ldr r0, _081E2328 @ =0x03002C6C
	str r5, [r0]
	str r4, [r5, #0x7c]
	adds r0, r5, #0
	adds r0, #0x80
	str r4, [r0]
	str r4, [r5, #0x78]
	str r4, [r5, #0x74]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl LinkShopManager_OnConnected
	movs r0, #1
_081E2322:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E2328: .4byte 0x03002C6C
