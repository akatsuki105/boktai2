	push {r4, lr}
	ldr r0, _0809C20C @ =0x0300013C
	ldr r0, [r0]
	cmp r0, #0
	beq _0809C206
	ldr r1, _0809C210 @ =0x000009FF
	adds r4, r0, r1
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _0809C206
	bl FUN_0809c08c
	movs r0, #0xff
	strb r0, [r4]
_0809C206:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C20C: .4byte 0x0300013C
_0809C210: .4byte 0x000009FF
