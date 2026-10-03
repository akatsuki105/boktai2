	push {lr}
	ldr r0, _0809C284 @ =0x0300013C
	ldr r1, [r0]
	cmp r1, #0
	beq _0809C27E
	ldr r2, _0809C288 @ =0x000009FC
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0809C27E
	adds r0, r1, #0
	bl FUN_0809bf88
_0809C27E:
	pop {r0}
	bx r0
	.align 2, 0
_0809C284: .4byte 0x0300013C
_0809C288: .4byte 0x000009FC
