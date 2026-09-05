	push {lr}
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _0807D176
	movs r0, #1
	rsbs r0, r0, #0
	b _0807D17A
_0807D176:
	bl Script_GetValue
_0807D17A:
	pop {r1}
	bx r1
	.align 2, 0
