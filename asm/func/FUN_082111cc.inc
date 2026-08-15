	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x25
	ldrb r0, [r6]
	bl FUN_082110dc
	cmp r0, #0
	beq _08211224
	ldr r0, _0821121C @ =0x0000086C
	adds r4, r5, r0
	ldr r0, [r4]
	movs r2, #0x87
	lsls r2, r2, #4
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	ldrb r1, [r6]
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	bl FUN_08049e5c
	ldr r1, _08211220 @ =0x00000874
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r1, r0, #0
	ldrb r0, [r6]
	adds r0, r1, r0
	bl Textbox_LookupString
	bl FUN_08049e30
	b _0821125E
	.align 2, 0
_0821121C: .4byte 0x0000086C
_08211220: .4byte 0x00000874
_08211224:
	ldr r2, _08211264 @ =0x0000086C
	adds r4, r5, r2
	ldr r0, [r4]
	adds r2, #4
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0x1b
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	bl FUN_08049e5c
	ldr r1, _08211268 @ =0x00000878
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r1, r0, #0
	ldrb r0, [r6]
	adds r0, r1, r0
	bl Textbox_LookupString
	bl FUN_08049e30
_0821125E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08211264: .4byte 0x0000086C
_08211268: .4byte 0x00000878
