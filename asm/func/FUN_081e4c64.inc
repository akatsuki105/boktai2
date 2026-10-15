	push {r4, lr}
	sub sp, #4
	str r1, [sp]
	ldr r1, _081E4C94 @ =0x00001610
	adds r4, r0, r1
	ldr r1, _081E4C98 @ =0xFFBFFFFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r0, _081E4C9C @ =0x03002CF0
	ldr r2, [r0]
	mov r0, sp
	movs r1, #0xa
	bl LinkShopManager_Send
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E4CA0
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r4]
	orrs r0, r1
	b _081E4CA6
	.align 2, 0
_081E4C94: .4byte 0x00001610
_081E4C98: .4byte 0xFFBFFFFF
_081E4C9C: .4byte 0x03002CF0
_081E4CA0:
	ldr r1, _081E4CB0 @ =0xFFFBFFFF
	ldr r0, [r4]
	ands r0, r1
_081E4CA6:
	str r0, [r4]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4CB0: .4byte 0xFFFBFFFF
