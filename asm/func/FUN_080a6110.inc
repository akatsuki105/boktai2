	push {lr}
	cmp r1, #0
	bne _080A6124
	ldr r1, _080A6120 @ =0x080A5EC5
	bl EntityCF58_SetUpdateCallback
	b _080A613A
	.align 2, 0
_080A6120: .4byte 0x080A5EC5
_080A6124:
	cmp r1, #1
	bne _080A6134
	ldr r1, _080A6130 @ =0x080A5FD1
	bl EntityCF58_SetUpdateCallback
	b _080A613A
	.align 2, 0
_080A6130: .4byte 0x080A5FD1
_080A6134:
	ldr r1, _080A6140 @ =0x080A5EC5
	bl EntityCF58_SetUpdateCallback
_080A613A:
	pop {r0}
	bx r0
	.align 2, 0
_080A6140: .4byte 0x080A5EC5
