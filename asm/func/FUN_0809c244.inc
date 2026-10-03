	push {lr}
	ldr r0, _0809C25C @ =0x0300013C
	ldr r0, [r0]
	cmp r0, #0
	beq _0809C258
	ldr r1, _0809C260 @ =0x000009FE
	adds r0, r0, r1
	ldrb r0, [r0]
	bl FUN_0809c08c
_0809C258:
	pop {r0}
	bx r0
	.align 2, 0
_0809C25C: .4byte 0x0300013C
_0809C260: .4byte 0x000009FE
