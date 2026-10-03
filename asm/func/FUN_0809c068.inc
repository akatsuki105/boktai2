	push {lr}
	ldr r0, _0809C07C @ =0x0300013C
	ldr r0, [r0]
	cmp r0, #0
	beq _0809C084
	ldr r1, _0809C080 @ =0x000009FC
	adds r0, r0, r1
	ldrh r0, [r0]
	b _0809C088
	.align 2, 0
_0809C07C: .4byte 0x0300013C
_0809C080: .4byte 0x000009FC
_0809C084:
	movs r0, #1
	rsbs r0, r0, #0
_0809C088:
	pop {r1}
	bx r1
