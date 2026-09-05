	push {lr}
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _0807AFF8
	movs r0, #0
	b _0807AFFC
_0807AFF8:
	bl Script_GetValue
_0807AFFC:
	pop {r1}
	bx r1
