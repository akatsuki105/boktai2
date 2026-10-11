	push {r4, r5, lr}
	ldr r4, _0809F704 @ =0x03000144
	ldr r0, [r4]
	cmp r0, #0
	beq _0809F738
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _0809F710
	b _0809F738
	.align 2, 0
_0809F704: .4byte 0x03000144
_0809F708:
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r0, [r0]
	b _0809F73C
_0809F710:
	bl VM_GetValue
	adds r5, r0, #0
	movs r3, #0
	ldr r0, [r4]
	ldrh r1, [r0, #0x18]
	cmp r3, r1
	bge _0809F738
	adds r4, r1, #0
	adds r1, r0, #0
	adds r1, #0xfc
	adds r2, r0, #0
_0809F728:
	ldrh r0, [r1]
	cmp r0, r5
	beq _0809F708
	adds r1, #0xf4
	adds r2, #0xf4
	adds r3, #1
	cmp r3, r4
	blt _0809F728
_0809F738:
	movs r0, #1
	rsbs r0, r0, #0
_0809F73C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
